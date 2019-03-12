# Савельев Денис Сергеевич, группа 747. #
### Практическая работа №3 ###
#### Задание: ####
- **Задание 1.** Необходимо реализовать функции для работы с односвязным списком.
- **Задание 2.** Необходимо реализовать функции для работы с двусвязным списком.
___
#### Ход работы: ####
   Была открыта среда разработки Dev-c++, был создан файл, написан код на языке С, была выполнена компиляция и проверка.
   В данных программах были реализованы функция для оодносвязных и двусвязных списках.

___
#### Результат: ####
  **Задание 1.** Было сделано так: пользователь вводит количество элементов (переменная N), в цикле for производится занесение данных с помощью функции (push_back), далее идеет поиск данных, которых ввел пользователь, по таблице с помощью функции (find) , далее пользователь вводит число, которое вставляется в конец списка с помощью функции (push_back), и число, которое вставляется в начало списка с помощью функции (push_front), далее пользватель вводит элемент, после которого будет вставлено значение с помощью функции (insertAfter),далее пользователь вводит эзначение, которое удалится из списка с помощью функции (removeFirst), и производится удаление всех элементов из списка.  
  
  **Таблица 1.**
  
| Входные данные | Выходные данные |
| :------------- | --------------: |
| 5              | 1 2 3 1 4       |
| 1 2 3 1 4      | 1 0 1           |
| 2 5 1          | 1 2 3 1 4 5     |
| 5              | 6 1 2 3 1 4 5   |
| 6              | 6 1 2 0 3 1 4 5 |
| 3 0            | 6 2 0 3 1 4 5   |
| 1              |                 |
  
  **Скриншот 1.**
  
[![example](https://pp.userapi.com/c849132/v849132119/14d1ac/833gEBtSG70.jpg)](пример1) 

  
  **Задание 2.** Было сделано так: пользователь вводит количество элементов (переменная N), в цикле for производится занесение данных с помощью функции (push_back), далее идеет поиск данных, которых ввел пользователь, по таблице с помощью функции (find) , далее пользователь вводит число, которое вставляется в конец списка с помощью функции (push_back), и число, которое вставляется в начало списка с помощью функции (push_front), далее пользватель вводит элемент, после которого будет вставлено значение с помощью функции (insertAfter),далее пользватель вводит элемент, перед которым будет вставлено значение с помощью функции (insertBefore), далее пользователь вводит эзначение, которое  удалит первый найденный элемент из списка с помощью функции (removeFirst), далее пользователь вводит эзначение, которое  удалит последний найденный элемент из списка с помощью функции (removeLast), и производится удаление всех элементов из списка.  
  
  **Таблица 2.**
  
| Входные данные | Выходные данные   |
| :------------- | ----------------: |
| 5              | 1 2 3 1 4         |
| 1 2 3 1 4      | 1 0 1             |
| 2 5 1          | 2 4 1 3 2 1       |
| 2              | 7 1 2 3 1 4 2     |
| 7              | 2 4 1 3 0 2 1 7   |
| 3 0            | 7 1 2 0 8 3 1 4 2 |
| 5 8            | 2 4 1 3 8 0 1 7   |
| 2              | 7 1 0 8 3 4 2     |
| 1              |                   |

  
  **Скриншот 2.**
  
[![example](https://pp.userapi.com/c849132/v849132119/14d1a5/JDKkcnVwpOs.jpg)](пример2)
___
#### Ссылки: ####  
- [Markdown Cheatsheet](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)
- [markdown-doc](https://github.com/OlgaVlasova/markdown-doc/blob/master/README.md#Parag)
