#include <iostream>

// STACK

const int STACK_SIZE{ 10 };

// 자료를 집어넣는 행위 = push
// 자료를 꺼내는 행위 = pop
enum Command
{
	PUSH = 1,	
	POP = 2
};

// stack 구조의 가장 위의 index = topIndex
// 배열과 topIndex를 묶기 위해 구조체 사용
struct Stack
{
	int container[STACK_SIZE];
	int topIndex{ -1 };
};

void PrintInfo()
{
	std::cout << "<STACK>" << std::endl;
	std::cout << "[1] Push" << std::endl;
	std::cout << "[2] Pop" << std::endl;
	std::cout << "--------" << std::endl;
}

void PrintStack(Stack& stack)
{
	std::cout << "---- stack ----" << std::endl;

	if (stack.topIndex < 0)				// stack에 원소가 없는 경우
	{									// 위의 topIndex를 -1로 초기화한 이유
		std::cout << "EMPTY" << std::endl;
		return;
	}

	for (int i = stack.topIndex; i >= 0; i--)	// stack 구조이므로 역순으로 출력
	{
		std::cout << stack.container[i] << std::endl;
	}
	std::cout << "---------------" << std::endl;
}

void Push(Stack& stack, int value)
{
	if (stack.topIndex >= STACK_SIZE - 1)		// 밑에 prefix이므로, STACK_SIZE와 같아도 안됨
	{											// STACK_SIZE와 같을 시, 
												// Push를 한번 더하면 사이즈 초과!
		// if의 조건 = 스택이 가득 찼다는 소리!		
		std::cout << "Stack is FULL !!!" << std::endl;
		return;
	}
	stack.container[++stack.topIndex] = value;	// prefix를 써야 먼저 증가한다
}

void Pop(Stack& stack)
{
	if (stack.topIndex < 0)						// if의 조건 = 스택에 아무것도 없을 때!
	{
		return;
	}

	std::cout << "pop : "<< stack.container[stack.topIndex--] << std::endl;
}												// postfix 해야만 출력 후 감소!

int main()
{
	Stack myStack;

	PrintInfo();

	while (true)
	{
		PrintStack(myStack);
		int command{};
		
		std::cout << std::endl;
		std::cout << "> ";
		std::cin >> command;

		switch (command)
		{
			case PUSH:
			{					// case 안에서 변수를 만들 때는, 명시적으로 중괄호 표시
				int value;
				std::cout << "\tpush value >> ";
				std::cin >> value;
				Push(myStack, value);
				break;
			}

			case POP:
				Pop(myStack);
				break;
								
			default:
				std::cout << "잘못된 명령어입니다." << std::endl;
				break;
		}
	}
}