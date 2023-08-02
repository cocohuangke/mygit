#include<stdio.h>
typedef enum msgtype {
	eInteger,
	eFloat,
	eString
}TMsgType;
typedef struct message {
	TMsgType type;
	union {
		int n;
		float f;
		const char* str;
	};
}TMessage;

void printMsg(TMessage msg)
{
	switch (msg.type)
	{
	case eInteger:
		printf("%d\n", msg.n);
		break;
	case eFloat:
		printf("%f\n", msg.f);
		break;
	case eString:
		printf("%s\n", msg.str);
		break;
	}
}
int main()
{
	TMessage msg[3];
	msg[0].type = eInteger;
	msg[0].n = 123;
	msg[1].type = eFloat;
	msg[1].f = 1.456;
	msg[2].type = eString;
	msg[2].str = "suyrfi";
	for (int i = 0; i < 3; i++)
		printMsg(msg[i]);
	return 0;
}
