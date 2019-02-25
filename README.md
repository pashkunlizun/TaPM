# Савельев Денис Сергеевич, группа 747. #
### Практическая работа №2 ###
#### Варианты и задание: ####
- **Вариант: 03. Сумма последовательности.** На вход подаётся число n ∈ N : n ≤ 2147483647, а также n чисел xi ∈ Z : |xi|≤ 2147483647 для любого целого i от 1 до n. Вывести значение <a href="https://www.codecogs.com/eqnedit.php?latex=\sum_{i=1}^{n}x_{i}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\sum_{i=1}^{n}x_{i}" title="\sum_{i=1}^{n}x_{i}" /></a>
- **Вариант 15. Сумма чётных кубов.** На вход подаётся число n ∈N : n ≤ 2147483647, а также n чисел xi ∈ Z : |xi| ≤ 2147483647 для любого целого i от 1 до n. Вывести значение <a href="https://www.codecogs.com/eqnedit.php?latex=\sum_{i=1}^{n}((i&plus;1)mod2)\cdot&space;x_{i}^{3}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\sum_{i=1}^{n}((i&plus;1)mod2)\cdot&space;x_{i}^{3}" title="\sum_{i=1}^{n}((i+1)mod2)\cdot x_{i}^{3}" /></a>
___
#### Ход работы: ####
   Была открыта среда разработки Dev-c++, был создан файл, написан код, была выполнена компиляция и проверка.
  
  **Вариант 03.** Было сделано так: сначало пользователь вводит количество элементов (переменная N), в цикле for производится вычисление суммы (переменная sum) введенных чисел (переменная n) пользователем.  
  *Например, пользователь ввел N = 4.  
  1 элемент: пользователь ввел число 3, переменная sum=0+3=3;  
  2 элемент: пользователь ввел число 5, переменная sum=3+5=8;  
  3 элемент: пользователь ввел число 1, переменная sum=8+1=9;  
  4 элемент: пользователь ввел число -8, переменная sum=9-8=1;  
  Вывод cуммы: 1*  
[![example](https://pp.userapi.com/c844321/v844321500/1af0a1/lCekv9sieb0.jpg)](пример1)  

  
  **Вариант 15.** Было сделано так: сначало пользователь вводит количество элементов (переменная N), в цикле for пользователь вводит число (переменная n), далее идет проверка на четность с помощью оператора if, если элемент четный, то к переменной sum добавляется четное число в кубе.  
  *Например, пользователь ввел N=5.  
  1 элемент: пользователь ввел число 3, проверка на четность 1/2 не равно 0, переходим к следующему элементу;  
  2 элемент: пользователь ввел число 2, проверка на четность 2/2 равно 0, переменная sum=0+2×2×2=8;  
  3 элемент: пользователь ввел число 1, проверка на четность 3/2 не равно 0, переходим к следующему элементу;  
  4 элемент: пользователь ввел число -1, проверка на четность 4/2 равно 0, переменная sum=8+(-1)×(-1)×(-1)=7;  
  5 элемент: пользователь ввел число -8, проверка на четность 5/2 не равно 0;  
  Вывод суммы: 7*  
[![example](https://pp.userapi.com/c852028/v852028315/c2e22/mwhVrJy5Sy4.jpg)](пример2)
___
#### Таблицы: ####
|03| Входные данные|Выходные данные|
| ------------- |:-------------:| -----:|
| N| 4| |
| n|3 5 1 -8||
| sum||1|

|15| Входные данные|Выходные данные|
| ------------- |:-------------:| -----:|
| N| 5| |
| n|3 2 1 -1 -8||
| sum||7|
___
#### Ссылки: ####  
- [Markdown Cheatsheet](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)
- [markdown-doc](https://github.com/OlgaVlasova/markdown-doc/blob/master/README.md#Parag)
