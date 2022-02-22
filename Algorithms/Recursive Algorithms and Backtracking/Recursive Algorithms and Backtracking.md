# Recursion

<p align="center">
  <img width="680
  src="https://github.com/andy489/Data_Structures_and_Algorithms_CPP/blob/master/assets/Recursive%20Algorithms%20and%20Backtracking%2001.png" alt="Example for recursion in nature" />
</p>

Рекурсията описва повтаряемост, по-конкретно:

- В математиката и лингвистиката – свързана с или включваща многократното приложение на правило, дефиниция или процедура с цел последващ резултат.
- В програмирането – отнасяща се за или включваща програма, за чието частично приложение се изисква прилагането на цялото, така че неговата изрична интерпретация изисква множество последващи изпълнения: рекурсивна подпрограма.
- Модерните Операционни системи (ОС) дефинират файловата си структура по рекурсивен начин. Състои се от главна директория, а вътре в нея има файлове и други директории.

Един обект наричаме рекурсивен, ако съдържа опростен свой вариант или е дефиниран от по-опростена своя версия. 

#### Характеристики на рекурсията:
  - разделя проблема на подпроблеми от същия тип
    - включва функция, която извиква себе си
    - функцията трябва да има базов случай (*дъно*)
    - на всяка стъпка от рекурсията трябва да се движим напред към базовия случай

#### Примери от живота:
  - две огледала насочени едно към друго
  - [фракталите](https://en.wikipedia.org/wiki/Fractal)

#### Видове рекурсия:
- пряка - когато една функция извиква сама себе си
- непряка - когато една функция извиква друга, а тя отсвоя страна извиква първата (или аналогично верига от n извикващи се функции)

#### Части на рекурсията:
- Разгъване - когато се извикват вложените функции
  - <img src="https://latex.codecogs.com/svg.latex?3!=3.2!">
  - <img src="https://latex.codecogs.com/svg.latex?2!=2.1!">
- Дъно - когато е достигнато условието за край
  - <img src="https://latex.codecogs.com/svg.latex?1!=1">
- Свиване - когато вложените функции една по една връщат резултатите си
  - <img src="https://latex.codecogs.com/svg.latex?{}2!=2.1!=2.1=2">
  - <img src="https://latex.codecogs.com/svg.latex?3!=2.2!=3.2=6">
- Дълбочина - броят на рекурсивните извиквания на функцията

#### Решаванена задачи чрез рекурсия
- Задачата се привежда до по-проста задача от същия вид
- Трябва задължително да има условие за край (осигуряващо *дъното* на рекурсията), и трябва разгъването на рекурсията постепенно да ниприближава до дъното
- Ако условието за дъно не е избрано коректно, рекурсията продължава докато се запълни стека, и програмата (или системата) блокира (препълва се стека - *stackoverflow*)
- Кодът който трябва да се изпълни по време на разгъването се поставя преди рекурсивното извикване, а кодът, който ще се изпълнява при свиването на рекурсията - след него

#### Рекурсия или итерация
- решение чрез рекурсия:

```cpp
long long fact(unsigned n){
	if (n < 2) return 1;
	return n * fact(n - 1);
}
```
- решение чрез итерация:

```cpp
long long fact(unsigned n){
	unsigned result = 1;
	for (unsigned i = 1; i <= n; i++) result *= i;
	return result;
}
```
Някой задачи се решават по-удачно чрез итерации, други чрез рекурсия.

#### Предимства и недостатъци
- Предимства
  - *По-прост код* - обяснението на много задачи чрез рекурсия е по-просто от еквивалентен итеративен алгоритъм
  - *Незаменимо за някои задачи* - някой задачи се решават най-елегантно чрез рекурсия
- Недостатъци 
  - *По-трудна за разбиране и осмисляне* - рекурсията не е толкова очевидно разбираема колкото итерацията например
  - *Коства повече памет* - всяко рекурсивно извикване заделя допълнителна памет от стека
  - *Експоненциално време за изпълнение*.
 ## Примери
 
 **Задача 1.** Да се напише рекурсивен метод който печата на конзолата следната фигура:
 
	**	***	****
	*	**	***
	#	*	**
	##	#	*
		##	#
		###	##
			###
			####
съответно за подадено число <img src="https://latex.codecogs.com/svg.latex?\Large&space;n=2,3,4,..."> и т.н.
 
 *Решение: *
 
 ```cpp
 #include <iostream>
void helpFunctionPrint(unsigned n, char symbol){
	for (size_t i = 0; i < n; i++) std::cout << symbol;
	std::cout << std::endl;
}
void recursionPrint(unsigned n){
	if (n == 0) return;
	helpFunctionPrint(n, '*');
	recursionPrint(n - 1);
	helpFunctionPrint(n, '#');
}
int main(){
	unsigned n;
	std::cin >> n;
	recursionPrint(n);
	return 0;
}
 ```
 
 #### Комбинаторни алгоритми чрез рекурсия
**Задача 2.** Да се генерират рекурсивно всички вектори с дължина 4 съставени само от 0 и 1.

*Решение:*

```cpp
#include <iostream>
#include <vector>

void printVector(std::vector<int> vector){
	unsigned n = vector.size();
	for (unsigned i = 0; i < n; i++)
		std::cout << vector[i] << ' ';
	std::cout << std::endl;
}

void generate01(unsigned indx, std::vector<int> vector){
	if (indx >= vector.size()) printVector(vector);
	else{
		for (int i = 0; i <= 1; i++){
			vector[indx] = i;
			generate01(indx + 1, vector);
		}
	}
}

int main(){
	std::vector<int> vector = { 8,8,8,8 };
	generate01(0, vector);
	return 0;
}
```

Аналогично, ако искаме да започнем на обратно като принтираме най-големия (според *лексикографска наредба*) вектор може да подходим така:

```cpp
#include <iostream>
#include <vector>

void printVector(std::vector<int> vector){
	unsigned n = vector.size();
	for (unsigned i = 0; i < n; i++)
		std::cout << vector[i] << ' ';
	std::cout << std::endl;
}

void generate01(unsigned indx, std::vector<int> vector){
	if (indx >= vector.size()) printVector(vector);
	else{
		for (int i = 1; i >= 0; i--){
			vector[indx] = i;
			generate01(indx - 1, vector);
		}
	}
}

int main(){
	std::vector<int> vector = { 8,8,8,8 };
	generate01(vector.size()-1, vector);
	return 0;
}
```
**Задача 3.** Напишете рекурсивна функция, която принтира всички 4-цифрени числа.

*Решение:*
Аналогично на предходната задача, това са всикчи 4-метни вектора с компоненти цифрите от 0,1,...,9, без тези които започват с 0.

```cpp
#include <iostream>
#include <vector>

void printVector(std::vector<int> vector){
	unsigned n = vector.size();
	if (vector[0] != 0){
		for (unsigned i = 0; i < n; i++)
			std::cout << vector[i];
		std::cout << std::endl;
	}
}

void generate4digitNumbers(unsigned indx, std::vector<int> vector){
	if (indx == vector.size()) printVector(vector);
	else{
		for (int i = 0; i <= 9; i++){
			vector[indx] = i;
			generate4digitNumbers(indx + 1, vector);
		}
	}
}

int main(){
	std::vector<int> vector = { 0,0,0,0 };
	generate4digitNumbers(0, vector);
	return 0;
}
```
**Задача 4.** Напишете рекурсивна функция, която извежда на конзолата всички двойни комбинации от 4 на брой елемента.

*Решение:*

Аналогично на горната задача, ще вземем първи вектор от две позиции където ще съхраняваме комбинациите и втори вектор с допустимите елементи от които ще се грнерират комбинациите. Отново ще генерираме всички двойни вектора с повторения, а от тях ще изберем само тези които например образуват монотонна редица. Отговора ще бъде точно исканите комбинации.

```cpp
#include <iostream>
#include <vector>
bool monotoneVector(std::vector<int> vector){
	for (size_t i = 0; i < vector.size() - 1; i++)
		if (vector[i] >= vector[i + 1]) return false;
	return true;
}

void printVector(std::vector<int> vector){
	if (monotoneVector(vector)){
		unsigned n = vector.size();
		for (unsigned i = 0; i < n; i++)
			std::cout << vector[i] << ' ';
		std::cout << std::endl;
	}
}

void generateComb(std::vector<int> set, std::vector<int>vector, unsigned indx){
	if (indx >= vector.size()) printVector(vector);
	else{
		for (unsigned i = 0; i < set.size(); i++){
			vector[indx] = set[i];
			generateComb(set, vector, indx + 1);
		}
	}
}

int main(){
	std::vector<int>set = { 4,8,9,22 };
	std::vector<int>vector = { 0,0 };

	generateComb(set, vector, 0);
	return 0;
}
```

# Backtracking

Бектракинг (на английски: *backtracking*, в превод „търсене с връщане“) е общо название на клас от алгоритми, които намират всички или някои решения на изчислителни задачи, по-специално задачи за удовлетворяване на ограничения. При този вид алгоритми решението се образува стъпка по стъпка, като за всяка стъпка се проверява дали удовлетворява поставените ограничения. При нарушаване на някое ограничение се отменя последната стъпка и се търси друга възможност. При изчерпване на възможностите се отменя предпоследната стъпка и т.н. до получаване на решение или до изчерпване на всички възможности.

Концептуално, частичните кандидат-решения се представят като възли от дървовидна структура от данни, т.е. пространството на решенията се изразява като дърво. Всеки възел (без кореновия) има само един родителски възел. Всяко частично кандидат-решение е родителски възел за кандидат-решенията, които се различават от него само с по една стъпка на разширяване, а листата на дървото са частични кандидат-решения, които няма накъде повече да бъдат разширявани.

Бектракинг алгоритъмът обхожда рекурсивно дървото на търсене от корена надолу към листата в дълбочина (*depth-first*). На всеки възел <img src="https://latex.codecogs.com/svg.latex?\Large&space;c">, алгоритъмът проверява дали <img src="https://latex.codecogs.com/svg.latex?\Large&space;c"> може да бъде завършено до валидно решение. Ако не може, цялото поддърво с корен в <img src="https://latex.codecogs.com/svg.latex?\Large&space;c"> се отстранява. В противен случай, алгоритъмът *(1)* проверява дали самият кандидат <img src="https://latex.codecogs.com/svg.latex?\Large&space;c"> е валидно решение, и ако да, съобщава за това на потребителя и *(2)* рекурсивно номерира всички поддървета на <img src="https://latex.codecogs.com/svg.latex?\Large&space;c">. Тези две проверки се дефинират по зададени от потребителя процедури. 

*Псевдо код за* **backtracking** *алгоритъм:*

```cpp
void Backtracking(Node node){
	if (node is solution)
		PrintSolution(node);
	else {
		for each child c of node
			if (c is perspective candidate){
				MarkPositionVisited(c);
				BackTracking(c);
				UnmarkPositionVisited(c);
			}
	}
}
```

**Задача 5.** Даденa е редица от положителни числа <img src="https://latex.codecogs.com/svg.latex?\Large&space;a"> и сума <img src="https://latex.codecogs.com/svg.latex?\Large&space;X">, да се намерят всички уникални комбинации в <img src="https://latex.codecogs.com/svg.latex?\Large&space;a"> чиято сума е равна на <img src="https://latex.codecogs.com/svg.latex?\Large&space;X">. Едно и също число от <img src="https://latex.codecogs.com/svg.latex?\Large&space;a"> може да бъде избирано неограничен брой пъти. Елементите в комбинациия <img src="https://latex.codecogs.com/svg.latex?\Large&space;C=(a_1,a_2,...,a_k)"> трябва да бъдат принтирани в ненамаляващ ред, т.е. <img src="https://latex.codecogs.com/svg.latex?\Large&space;a_1\le{a_2}\le{,...,\le{a_k}">. Комбинациите сами по себе си трябва да бъдат сортирани в нарастващ ред, т.е., комбинацията с най-малък първи елемент трябва да бъде принтирана на първо място. Ако не съществува възможна комбинация удовлетворяваща условието да се принтира подходящо съобщение.

*Пример:*

	Вход: a={2,4,6,8}, X=8

	Изход:   2, 2, 2, 2
	         2, 2, 4	 
      	 2, 6	
        	 4, 4	 
        	 8
*Решение:*

**Алгоритъм:**

- 1. Сортираме масива (не намаляващ);
- 2. Премахваме всички дубликати от масива;
- 3. Използваме рекурсия и backtracking за решаване проблемa;
  - (A) Ако в даден текущата сума стане равна на 0, тогава добавяме този вектор към резултата (вектор от вектори);
  - (Б) В противен случай, ако е сумата стане отрицателна - това не е потенциално решение и го игнорираме;
  - (C) Докато индекса е по-малък от дължината на вектора с елементи и сумата е не по-малка от 0 - викаме рекурсията за всички останали елементи (вкл. и потенциално добавения), като преди нея сме добавили потенциалния елемент във вектора с потенциалния резултат, а след нея (рекурсията) сме увеличили индекса и сме премахнали елемента от списъка който не води до потенциално решение.

```cpp
#include <iostream>
#include <set> 
#include <vector>
#include <algorithm>

void printVecOfVecs(std::vector<std::vector<int>> a)
{
	if (a.size() == 0) std::cout << "No such combination\n";
	else // Принтираме всички възможни комбинации във вектора от вектори
	{
		for (unsigned i = 0; i < a.size(); i++)
		{
			if (a[i].size() > 0)
			{
				std::cout << "(";
				for (unsigned j = 0; j < a[i].size(); j++)
				{
					if (j == a[i].size() - 1) std::cout << a[i][j];
					else std::cout << a[i][j] << ',';
				}
				std::cout << ")\n";
			}
		}
	}
}

void findSumComb(std::vector<int> a, int sum, 
	std::vector<std::vector<int>>& res, std::vector<int> r, unsigned i)
{
	// Ако текущата сума стане отрицателна
	if (sum < 0) return;

	// Ако получим точната сума
	if (sum == 0)
	{
		res.push_back(r);
		return;
	}

	// Викаме рекурсията за всички останали елементи, 
	// които са със стойност по малка от текущата сума
	while (i < a.size() && sum - a[i] >= 0)
	{ // До всеки елемент в масива започвайки от i, 
	  // който може да се включи в сумата
		r.push_back(a[i]); // добавяме го към потенциалната комбинация

		// Викаме рекурсията за останалите елементи (вкл. първия)
		findSumComb(a, sum - a[i], res, r, i); // без повтарящи се елементи: i+1, вместо i
		i++;

		// Махаме елементa от списъка, който не води 
		// до потенциална комбинация (backtracking)
		r.pop_back();
	}
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& a, int sum)
{
	// sort input array 
	sort(a.begin(), a.end());

	// remove duplicates 
	a.erase(unique(a.begin(), a.end()), a.end());

	std::vector<int> r;
	std::vector<std::vector<int> > res;
	findSumComb(a, sum, res, r, 0);
	return res;
}
int main()
{
	std::vector<int> a = { 4,2,6,2,8,4 };
	int X = 8;
	// Сортираме вектора, за да може да използваме готовата функция за 
	// премахване на дубликатите
	sort(a.begin(), a.end());
	// Премахваме дублиращите се стойности от вече сортирания вектор
	a.erase(unique(a.begin(), a.end()), a.end());

	std::vector<std::vector<int>> res = combinationSum(a, X);
	printVecOfVecs(res);
	return 0;
}
```
**Задача 5.** (*Класически пример*) Да се намерят всички възможни начини, по които може да се поставят 8 кралици на шахматна дъска, така че да не се „бият“ една-друга.

*Решение:* [РЕШЕНИЕТО Е ИМПЛЕМЕНТИРАНО ТУК](https://github.com/andy489/Data_Structures_and_Algorithms_CPP/tree/master/Algorithms/8%20Queens%20Problem)

**Задача 6.** Даден е лабиринт, представен чрез матрица от клетки. Целта е да намерим всички пътища от стартовата позиция (клетка с координати (0,0)) до финалната позиция (клетка със символ 'e').
- празните (проходими) клетки са маркирани с '-';
- стените (непроходимите клетки) са маркирани с '*';
На първия и втория ред ще получим размерите на лабиринта. На следващите редове ще получаваме клетките на лабиринта.
Редът на пътищата е без значение.

*Пример:*
```
Вход:   Изход:
3	RRDD
3	DDRR
---
-*-
--е

Вход:   Изход:
3	DRRRRU
5 	DRRRUR
-**-e
-----
*****
```
*Решение:* [РЕШЕНИЕТО Е ИМПЛЕМЕНТИРАНО ТУК](https://github.com/andy489/Data_Structures_and_Algorithms_CPP/blob/master/Algorithms/Find%20All%20Paths%20in%20Labyrinth/Find%20all%20Paths%20in%20labyrinth.cpp)

**Задача 6.** Да се намерят всички решения на дадено частично запълнено судоку 9х9.

*Решение:* [РЕШЕНИЕТО Е ИМПЛЕМЕНТИРАНО ТУК](https://github.com/andy489/Data_Structures_and_Algorithms_CPP/blob/master/Algorithms/Sudoku/Sudoku%20solver.cpp)

**Задача 7.** Напишете рекурсивен bubbleSort алгоритъм. Оптимизирайте го в рекурсивен cocktailSort алгоритъм.
 
*Коментар:* тъй като bubbleSort-а при първата итерация (обхождане на масива в тоя случай) изпраща най-големия елемент в края на списъка, то може рекурсивно да го извикаме отново за всички елементи на списъка без последния и така докато не достигнем дължина от един елемент.

```cpp
#include <iostream>

int list[] = { 10,2,3,4,5,6,7,8,9,1 };
unsigned n = sizeof(list) / sizeof(list[0]);

unsigned countSwaps(0);
unsigned countChecks(0);
unsigned recurCalls(0);

bool swapped = false;

void displayList(){
	for (unsigned i = 0; i < n; i++)
		std::cout << list[i] << " ";
	std::cout << std::endl;
}

void bubbleSortRecursive(unsigned n){
	if (n ==  1) return;
	for (int i = 0; i < n; i++){
		countChecks++;
		if (list[i] > list[i + 1]){
			swapped = true;
			countSwaps++;
			std::swap(list[i], list[i + 1]);
		}
	}
	if (!swapped)
		return;
	swapped = false;
	recurCalls++;
	bubbleSortRecursive(n - 1);

}

int main(){
	bubbleSortRecursive(n);
	displayList();
	std::cout << "Total swaps: " << countSwaps << ".\n";
	std::cout << "Total checks: " << countChecks << ".\n";
	std::cout << "Recur depth: " << recurCalls << ".\n";
	return 0;
}
```

*Аналогично на cocktailSort може да напишем подобна рекурсивна функция на bubbleSort, която обхожда списъка отзад напред и да направим така, че рекурсивно да се извикват една друга двете функции на bubbleSort за обхождане напред и обхождане назад съответно. Къде ще бъде дъното на рекурсиите в такъв случай?*

```cpp
#include <iostream>

int list[] = { 10,2,3,4,5,6,7,8,9,1 };
unsigned n = sizeof(list) / sizeof(list[0]);

unsigned countSwaps(0);
unsigned countChecks(0);
unsigned recurCalls(0);

bool swapped = false;

void displayList(){
	for (unsigned i = 0; i < n; i++)
		std::cout << list[i] << " ";
	std::cout << std::endl;
}

void bubbleSortRecursiveBackward(int startIndx, int endIndx);

void bubbleSortRecursiveForward(int startIndx, int endIndx){
	if (endIndx == n / 2 - 1) return;
	for (int i = startIndx; i < endIndx; i++){
		countChecks++;
		if (list[i] > list[i + 1]){
			swapped = true;
			countSwaps++;
			std::swap(list[i], list[i + 1]);
		}
	}
	if (!swapped)
		return;
	swapped = false;
	recurCalls++;
	bubbleSortRecursiveBackward(startIndx, endIndx - 1);

}

void bubbleSortRecursiveBackward(int startIndx, int endIndx){
	if (startIndx == n / 2 + 1) return;
	for (int i = endIndx; i > startIndx; i--){
		countChecks++;
		if (list[i] < list[i - 1]){
			swapped = true;
			countSwaps++;
			std::swap(list[i], list[i - 1]);
		}
	}
	if (!swapped)
		return;
	swapped = false;
	recurCalls++;
	bubbleSortRecursiveForward(startIndx + 1, endIndx);
}

int main(){
	bubbleSortRecursiveForward(0, n - 1);
	displayList();
	std::cout << "Total swaps: " << countSwaps << ".\n";
	std::cout << "Total checks: " << countChecks << ".\n";
	std::cout << "Recur depth: " << recurCalls << ".\n";
	return 0;
}
```
**Задача 8.** (*Площадки в матрица*) Нека дефинираме *площадка* в матрица от клетки като множество от клетки, между всеки две от които има път (*можеството има една компонента на свързаност*). Път между две клетки има когато двете клетки имат точко една обща стена (*тук „път“ може да се дефинира и когато клетките имат едно общо ръбче, но в нашия случай ще разглеждаме пътя като съществуващ, ако клетките имат точно една обща стена. В лучая думата „точно“ показва, че клетките трябва да са различни*). Напишете програма, която намира всички площадки в дадена матрица. На конзолата принтирайте общия брой на площадките, а на отделни редове принтирайте следната информация за всяка площадка: нейната позиция (*най-горен ляв ъгъл*) и размер (*брой клетки*).

Подредете площадките по размер (в намаляващ ред), така че най-голямата площадка да е принтирана първа. Ако няколко площадки имат един и същи размер, сортирайте ги по позиция, първо по редове, после по колони от най-горния ляв ъгъл. Така, ако има две площадки с един и същ размер, тази която е над и/или от ляво на другата ще се принтира първа.

Примери:
![](https://github.com/andy489/Data_Structures_and_Algorithms_CPP/blob/master/assets/Recursive%20Algorithms%20and%20Backtracking%2002.png)
 
 *Решение:*
 
 ```cpp
//#define ROWS 5
//#define COLS 10

#include <iostream>
#include <vector>
#include <algorithm>

/* площадка отбелязваме с тире '-',
   празна клетка отбелязваме със звездичка '*' */

char** readMatrix(unsigned& rows, unsigned& cols)
{
	std::cout << "Enter number of rows: ";
	std::cin >> rows;
	std::cout << "Enter number of columns: ";
	std::cin >> cols;
	/* заделяме динамично памет за матрицата */
	char** matrix = new char*[rows];
	for (unsigned i = 0; i < rows; i++)
	{
		matrix[i] = new char[cols];
	}
	for (unsigned r = 0; r < rows; r++)
	{
		for (unsigned c = 0; c < cols; c++)
		{
			std::cin >> matrix[r][c];
		}
	}
	return matrix;
}

template <typename T>
void releaseMatrix(T** matrix, unsigned rows, unsigned cols)
{
	for (unsigned i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

bool** createDublicateBool(unsigned rows, unsigned cols)
{
	bool** visited = new bool*[rows];
	for (unsigned i = 0; i < rows; i++)
	{
		visited[i] = new bool[cols];
	}
	for (unsigned i = 0; i < rows; i++)
	{
		for (unsigned j = 0; j < cols; j++)
		{
			visited[i][j] = false;
		}
	}
	return visited;
}

struct Area
{   /* създаваме си клас описващ площадка*/
	unsigned startIndx;
	unsigned endIndx;
	unsigned size;
};

void releaseVectorOfPointers(std::vector<Area*> areas)
{
	for (int i = 0; i < areas.size(); i++)
	{
		delete (areas[i]);
	}
	areas.clear();
}

/* Хардкоднати матрици за тестване в течение на имплементация на решението */
//char P[ROWS][COLS] = { { '-', '-', '-', '-', '*', '*', '*', '-', '-','-' },
//					   { '-', '-', '-', '*', '*', '-', '*', '*', '-', '*' },
//					   { '-', '-', '*', '*', '-', '-', '-', '*', '*', '*' },
//					   { '-', '-', '*', '*', '*', '-', '*', '*', '*', '*' },
//					   { '-', '*', '*', '*', '*', '*', '*', '*', '*', '-' } };
//
//char Q[ROWS][COLS] = { { '*', '-', '-', '*', '-', '-', '-', '*', '-', '-' },
//					   { '*', '-', '-', '*', '-', '-', '-', '*', '-', '-' },
//					   { '*', '-', '-', '*', '*', '*', '*', '*', '-', '-' },
//					   { '*', '-', '-', '*', '-', '-', '-', '*', '-', '-' },
//					   { '*', '-', '-', '*', '-', '-', '-', '*', '-', '-' } };
//
//char R[ROWS][COLS] = { { '-', '-', '-', '*', '-', '-', '-', '*', '-', '*' },
//					   { '-', '-', '-', '*', '-', '-', '-', '*', '-', '*' },
//					   { '-', '-', '-', '*', '-', '-', '-', '*', '-', '*' },
//					   { '-', '-', '-', '-', '*', '-', '*', '-', '-', '*' },
//					   { '*', '*', '*', '*', '*', '*', '*', '*', '*', '*' } };

template  <typename T>
void printMatrix(T** M, unsigned rows, unsigned cols)
{   	/* помощна функция за принтиране на оригиналната матрица, за тестване*/
	for (unsigned r = 0; r < rows; r++)
	{
		for (unsigned c = 0; c < cols; c++)
		{
			std::cout << M[r][c] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void printVectorWithAreas(std::vector<Area*>& areas)
{   /* помощна функция за принтиране на вектора от площадки */
	for (unsigned i = 0; i < areas.size(); i++)
	{
		std::cout << "Area #" << i + 1 << " at (" << areas[i]->startIndx << ", "
			<< areas[i]->endIndx << "), size: " << areas[i]->size << "\n";
	}
}

bool isSafe(unsigned row, unsigned col, unsigned rows, unsigned cols, char** M, bool** (&visited))
{	/* ред и колона не са извън размера на матрицата и клетката не е посетена все още*/
	return (row >= 0) && (row < rows) && (col >= 0) && (col < cols) && (M[row][col] == '-' && !visited[row][col]);
}

unsigned countSizeDFS(unsigned row, unsigned col, unsigned rows, unsigned cols, char** M, bool** (&visited), unsigned K, int* rowBr4, int* colBr4,unsigned& size)
{
	visited[row][col] = true; /* маркираме клетката като посетена */
	for (unsigned k = 0; k < K; k++)
		if (isSafe(row + rowBr4[k], col + colBr4[k], rows, cols, M, visited))
		{
			size++;
			countSizeDFS(row + rowBr4[k], col + colBr4[k], rows, cols, M, visited, K, rowBr4, colBr4,size);
		}
	return size;
}

int countIslandsAndAreas(char** M, unsigned rows, unsigned cols, std::vector<Area*>& areas, bool** (&visited), unsigned K, int* rowBr4, int* colBr4,unsigned& size)
{
	int count = 0; /* Инициализираме брояча на 0, като започваме да обхождаме всички клетки на матрицата */

	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < cols; j++)
		{
			/* Ако клетката не е посетена и е част от площадка*/
			if (M[i][j] == '-' && !visited[i][j])
			{
				/* инкрементираме броя на площадките */
				count++;
				/* не е посещавана до сега - обхождаме и посещаваме всички клетки в тази площадка */
				unsigned areaSize = countSizeDFS(i, j, rows, cols, M, visited, K, rowBr4, colBr4,size); /* Дълбичинно търсене Depth First Search (DFS) */

				//std::cout << "Area #" << count << " at (" << i << ", " << j << "), size: " << areaSize << "\n";

				Area* a = new Area(); /* оператор new => оператор delete */
				a->startIndx = i;
				a->endIndx = j;
				a->size = areaSize;
				areas.push_back(a);
			}
			size = 1;
		}
	return count;
}
int main()
{
	/* Помощни масиви за достигане на индексите на реда и колоната
		на всички 8 съседа на дадена клетка (дефиниция с ръбче)*/
	int rowBr8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int colBr8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	/* Помощни масиви за достигане на индексите на реда и колоната
	на всички 4 съседа на дадена клетка (дефиниция с точно една обща стена)*/
	int rowBr4[] = { -1,  0, 0, 1 };
	int colBr4[] = { 0, -1, 1, 0 };

	unsigned K = sizeof(rowBr4) / sizeof(rowBr4[0]);

	unsigned rows, cols;
	char** M = readMatrix(rows, cols);
	std::cout << "\nOriginal matrix is:\n\n";
	printMatrix(M, rows, cols);

	/* булева матрица дубликат, на която ще отбелязваме дали сме посетили дадена клетка от оригиналната матрица */
	bool** visited = createDublicateBool(rows, cols);
	//std::cout << "\nDublicate bool matrix is:\n\n";
	//printMatrix(visited, rows, cols);

	std::vector<Area*> areas; /*създаваме си вектор от пойнтъри към площадки,
						  като не забравяме после да изтрием поинтърите*/

	unsigned size(1); /* инициализираме с конструктор с параметър променливата size да приема
					  стартова стойност 1, защото вече сме намерили площадка с поне единица размер*/

	unsigned totalCount = countIslandsAndAreas(M, rows, cols, areas, visited, K, rowBr4, colBr4,size);
	std::cout << "Total areas found: " << totalCount << '\n';
	std::sort(areas.begin(), areas.end(), [](Area const *a, Area const *b) {return a->size > b->size; });
	printVectorWithAreas(areas);

	releaseMatrix(M, rows, cols);
	releaseMatrix(visited, rows, cols);
	releaseVectorOfPointers(areas);
	
	return 0;
}

```
