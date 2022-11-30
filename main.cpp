#include <iostream>

// STACK

const int STACK_SIZE{ 10 };

// �ڷḦ ����ִ� ���� = push
// �ڷḦ ������ ���� = pop
enum Command
{
	PUSH = 1,	
	POP = 2
};

// stack ������ ���� ���� index = topIndex
// �迭�� topIndex�� ���� ���� ����ü ���
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

	if (stack.topIndex < 0)				// stack�� ���Ұ� ���� ���
	{									// ���� topIndex�� -1�� �ʱ�ȭ�� ����
		std::cout << "EMPTY" << std::endl;
		return;
	}

	for (int i = stack.topIndex; i >= 0; i--)	// stack �����̹Ƿ� �������� ���
	{
		std::cout << stack.container[i] << std::endl;
	}
	std::cout << "---------------" << std::endl;
}

void Push(Stack& stack, int value)
{
	if (stack.topIndex >= STACK_SIZE - 1)		// �ؿ� prefix�̹Ƿ�, STACK_SIZE�� ���Ƶ� �ȵ�
	{											// STACK_SIZE�� ���� ��, 
												// Push�� �ѹ� ���ϸ� ������ �ʰ�!
		// if�� ���� = ������ ���� á�ٴ� �Ҹ�!		
		std::cout << "Stack is FULL !!!" << std::endl;
		return;
	}
	stack.container[++stack.topIndex] = value;	// prefix�� ��� ���� �����Ѵ�
}

void Pop(Stack& stack)
{
	if (stack.topIndex < 0)						// if�� ���� = ���ÿ� �ƹ��͵� ���� ��!
	{
		return;
	}

	std::cout << "pop : "<< stack.container[stack.topIndex--] << std::endl;
}												// postfix �ؾ߸� ��� �� ����!

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
			{					// case �ȿ��� ������ ���� ����, ��������� �߰�ȣ ǥ��
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
				std::cout << "�߸��� ��ɾ��Դϴ�." << std::endl;
				break;
		}
	}
}