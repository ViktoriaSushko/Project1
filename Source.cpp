#include<iostream>
#include<iomanip>
#include<forward_list>
#include <list>
using namespace std;
template <typename T>
void printList(const forward_list<T>& list) {
	for (auto i = list.begin(); i != list.end(); i++)
	{
		cout << *i << "\t";
	}
	cout << "\n\n";
}


int main()
{
	setlocale(LC_ALL, "RU");
	int menu;
	do {
		cout << "Выберите задание\n";
		cin >> menu;
		switch (menu) {
		case 1: {
			list<int>::iterator it;
			it++;
			++it;

		}
			  break;

		case 2: {
			forward_list<int> list1;                     // пустой список
			forward_list<int> list2(5);                  // list2 имеет 5 элементов, каждый из которых имеет значение по умолчанию
			forward_list<int> list3(5, 2);               // list3 состоит из 5 чисел, каждое число равно 2
			forward_list<int> list4{ 1, 2, 4, 5 };       // list4 состоит из чисел 1, 2, 4, 5
			forward_list<int> list5 = { 1, 2, 3, 4, 5 }; // list5 состоит из чисел 1, 2, 3, 4, 5
			forward_list<int> list6(list4);              // list6 - копия списка list4
			forward_list<int> list7 = list4;             // list7 - копия списка list4
			forward_list<int> list8({ 1, 2, 3, 4, 5, 6 }); // list8  состоит из чисел 1, 2, 3, 4, 5, 6
			break;
		}
		case 3: {
				forward_list<int> numbers = { 1, 2, 3, 4, 5 };
				int first = numbers.front();  
				for (int n : numbers)
			    cout << n << "\t";
				cout << std::endl;				
		}
			  break;
		case 4: {
				forward_list<int> numbers = { 1, 2, 3, 4, 5 };
				numbers.push_front(10);
				numbers.pop_front();
				auto prev = numbers.before_begin();
				auto current = numbers.begin();
				auto end = numbers.end();
				while (current != end)
				{
					cout << *current << "\t";
					current++;
				}
				cout << endl;					
				if (numbers.empty())
					cout << "The forward_list is empty" << endl;
				else
					cout << "The forward_list is not empty" << endl;				
				numbers.resize(4);  
				numbers.resize(6, 8); 
				printList(numbers);
			break;
		}
		case 5: {
			forward_list<int> numbers = { 1, 2, 3, 4, 5 };
			numbers.assign({ 21, 22, 23, 24, 25 }); 
			printList(numbers);
			numbers.assign(4, 3); 
			printList(numbers);
			list<int> values = { 6, 7, 8, 9, 10, 11 };
			auto start = ++values.begin(); 
			auto end = values.end();
			numbers.assign(start, end); 
			printList(numbers);
		}
			  break;
		case 6: {
				forward_list<int> numbers = { 7, 8 };
				numbers.emplace_front(-3); 
				auto iter = numbers.begin();
				iter = numbers.emplace_after(iter, -2); // добавляем после итератора число -2
				iter = numbers.insert_after(iter, -1);				
				iter = numbers.insert_after(iter, 3, 0);    
				list<int> values = { 1, 2, 3 };
				iter = numbers.insert_after(iter, values.begin(), values.end()); 				
				numbers.insert_after(iter, { 4, 5 }); // добавляем список { 4, 5 }				
				for (int n : numbers)
			    cout << n << "\t";
				cout << endl;		
			
		}
			  break;
		case 7: {
			forward_list<int> numbers = { 1, 2, 3, 4, 5, 6, 7 };
			numbers.pop_front();			
			auto iter = numbers.erase_after(numbers.begin());			
			numbers.erase_after(iter, numbers.end());
			printList(numbers);
		}
			  break;
		}
	} while (menu != 0);
}
