Задачи по курсу программирования на C

ЗАДАНИЕ 1
	Объявить вещественные переменные a, b и с и задать их значения. Предполагая, что a, b, c есть коэффициенты квадратного уравнения вывести на консоль значения их корней х1, х2. Следует подобрать такие значения коэффициентов, при которых корни будут существовать.
	Примечание. Для выполнения задания потребуется функции вычисления квад-ратного корня (возведение в степень), а так же вывод данных на консоль.
	Возведение в степень - подключаем заголовочный файл	 math.h и исполь-зуем функцию pow, первым параметром которого должен быть возводимое значение, а вторым – степень, тип данных double.
	Вывод данных - заголовочный файл stdio.h, функция printf, первым параметром является форматная строка, а последующие – переменные, значения которых необхо-димо вывести.

ЗАДАНИЕ 2
	Объявить массив данных типа double размером 3 на 3. Ввести с консоли его значения, вывести на консоль сумму его элементов, расположенных на главной диаго-нали и сумму элементов, расположенных на  побочной диагонали.
	Объявить массив данных типа int размером 2 на 2. Ввести с консоли его значе-ния, вывести на консоль квадрат данной матрицы.

ЗАДАНИЕ 3
Ввести с консоли строку символов произвольной длины (до 80 символов). По-менять в ней все маленькие символы ‘a’ и ‘b’ на заглавные и вывести на консоль полу-ченную строку.

ЗАДАНИЕ 4
	Написать функции, вычисляющие периметр и площадь треугольника по значе-ниям длин трёх его сторон. Разместить их в отдельном модуле (отличном от того, где располагается функция main( )). Ввести с консоли значения длин сторон треугольника (с проверкой на корректность неравенства треугольника) и выдать на консоль вычис-ленные с помощью написанных функций значения его периметра и площади.
ЗАДАНИЕ 5
	Разместить в динамической памяти 2 массива – 2 матрицы размерностью n на n с элементами типа double (значения n и элементы массивов ввести с консоли). А также ввести с консоли знак операции: '+', '-' или '*'. Написать функцию, вычисляющую сум-му, разность или произведение данных матриц (их передать по указателю) и возвра-щающую указатель на массив-результат. Разместить эту функцию в отдельном модуле (отличном от того, где располагается функция main()). Выдать на консоль значения по-лученного вектора.

ЗАДАНИЕ 6
	Создать текстовый файл с записями следующего вида:
Иванов Петр Сергеевич 1975
Сидоров Николай Андреевич 1981
….
Воробьянинов Ипполит Матвеевич 1978

	Прочитать данные из этого файла и записать в другой только те строки, которые относятся к родившимся позднее 1980 года.

ЗАДАНИЕ 7
	Объявить тип-структуру humen, включающую имя человека, фамилию и год рождения. Объявить два массива из четырёх элементов типа humen. Ввести с консоли или из файла элементы одного массива и построить на их основе другой, упорядочив элементы по годам рождения. Вывести результат.

ЗАДАНИЕ 8
	Создать текстовый файл с записями, включающие имя/фамилию человека, год рождения, пол и рост (в метрах). Упорядочить элементы по году рождения, име-ни/фамилии, полу или росту. Вывести результат. Указать элемент, по которому следует упорядочить, через консоль. А также реализовать возможность задавать несколько по-лей для упорядочивания.

ЗАДАНИЕ 9
	Реализовать программу-калькулятор с возможностью выполнения арифметиче-ских действий (+, -), унарный и бинарный вариант. У пользователя запрашивается вы-ражение, например, "-123,5 + 4 - 456+56", программа должна решить выражение. Для разбора входной строки использовать функцию strok.

ЗАДАНИЕ 10
	Написать программу вычисления максимального числа из введенных пользова-телем в виде одной строки.  Использовать для этого макрос (без функции), на вход ко-торому подается массив чисел и их количество.

ЗАДАНИЕ 11
	Создать в отдельном модуле функции с переменным количеством аргументов, которая вычисляет их сумму, максимум, минимум, среднее арифметическое.

ЗАДАНИЕ 12
	Написать программу-календарь. Пользователь может указать даты в формате:
	- гггг.мм.дд – программа вычисляет день недели соответствующий данной дате;
	- гггг.мм – программа выводит календарь за данный месяц;
	- гггг – календарь за год;
	- now – текущую дату.

ЗАДАНИЕ 13
	Написать программу, обрабатывающую получение сигналов (SIGABRT, SIGFPE, SIGILL, SIGINT, SIGSEGV, SIGTERM). Также программа, может возбуждать эти сигналы по указанию пользователя. В качестве обработчика должно быть реализо-вано логирование (вывод на консоль).

ЗАДАНИЕ 14
	Написать программу с использованием нелокального перехода setjmp/longjmp, которая вычисляет сумму чисел Фибоначчи (начиная с1, 1,...). Использовать рекурсив-ную функции для вычисления суммы, в качестве механизма возврата из вложенных вызовов использовать нелокальный переход.

ЗАДАНИЕ 15
	Дано натуральное число N. Выведите все его цифры по одной, в обычном по-рядке (а потом в обратном), разделяя их пробелами или новыми строками. Например: 179 => 1 7 9; 179 => 9 7 1
При решении этой задачи нельзя использовать строки, списки, массивы (ну и циклы, разумеется).


ЗАДАНИЕ 16
	Написать программу подсчитывающая количество битов, выставленных в еди-ницу у числа типа long и double. Сами значения чисел вводятся с клавиатуры.    
