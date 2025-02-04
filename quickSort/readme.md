
## Описание
Быстрая сортировка — это эффективный алгоритм сортировки, который использует метод "разделяй и властвуй". Он работает путем выбора опорного элемента (pivot) и разделения массива на две части: элементы, меньшие опорного, и элементы, большие опорного. Затем алгоритм рекурсивно сортирует обе части.

## Принцип работы
- Выбор опорного элемента: Обычно выбирается первый, последний или средний элемент массива, хотя могут использоваться и другие стратегии.
- Разделение: Массив делится на две части:
  - Элементы, меньшие опорного.
  - Элементы, большие опорного.
- Рекурсия: Рекурсивно применяется быстрая сортировка к обеим частям.
- Объединение: Поскольку элементы уже находятся в нужном порядке относительно опорного, нет необходимости в явном объединении.

## Временная сложность
- Лучший случай: O(n log n) — когда массив делится на две равные части.
- Средний случай: O(n log n) — в большинстве случаев.
- Худший случай: O(n²) — когда массив уже отсортирован или все элементы одинаковые (если опорный элемент выбирается неудачно).
## Преимущества
- Быстрая сортировка обычно работает быстрее, чем другие O(n log n) алгоритмы, такие как сортировка слиянием и пирамидальная сортировка, благодаря меньшему количеству операций по сравнению с ними.
- Хорошо работает на больших массивах.
## Недостатки
- Неустойчивая сортировка: порядок равных элементов может измениться.
- В худшем случае может быть медленнее, чем другие алгоритмы сортировки, если не реализована оптимизация выбора опорного элемента.
## Оптимизации
- Выбор опорного элемента: Использование медианы из трех (первый, последний и средний элементы) для выбора опорного элемента может помочь избежать худшего случая.
- Сортировка небольших массивов: Для небольших массивов (например, менее 10 элементов) можно использовать сортировку вставками, так как она быстрее для малых объемов данных.
- Рекурсивные вызовы: Использование итеративного подхода вместо рекурсивного для уменьшения использования стека.

Вход:
строка 1:
	целое N от 0 до 2000000 -- длина массива
строка 2:
	N целых чисел -- значения элементов массива

Выход:
	Значения элементов массива упорядоченные по возрастанию с помощью алгоритма Quick Sort, разделенные пробелами.
	Время на сортировку -- 3 секунды.

Исполняемый файл + данные не более 4 * N + 4Mb

Пример 1
Вход:
3
4 -1 2
Выход:
-1 2 4
