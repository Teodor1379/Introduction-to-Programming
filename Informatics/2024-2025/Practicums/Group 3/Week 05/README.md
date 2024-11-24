# Седмица 5

## Задача 1

Създайте програма, която прочита от стандартния вход цяло неотрицателно число `n` и извежда на стандартния изход резлутата от следните изрази:

1. `1 + 2 + 3 + ... + n`
2. `1^2 + 2^2 + 3^3 + ... + n^2`
3. `1^3 + 2^3 + 3^3 + ... + n^3`
4. `1.2 + 2.3 + 3.4 + ... + n.(n+1)`
5. `1.2 + 3.4 + 5.6 + ... + (2n - 1).2n`
6. `1.2.3 + 2.3.4 + 3.4.5 + ... + n.(n + 1).(n + 2)`
7. `n! = 1.2.3 ... n`
8. `n!! = n.(n-2)(n-4)...`
9. `n!!! = n.(n-3).(n-6)`

## Задача 2

Създайте програма, която прочита от стандартния вход цяло неотрицателно число `n` и реалнозначно число `x`. На стандартния изход изведете резултата от `x^n`, но без да използвате вградените функции от библиотеката `<math.h>`.

## Задача 3

Създайте програма, която прочита от стандартния вход цяло неотрицателно число `n` и извежда на стандартния изход следните резултати, но без да използвате оператор `if`:

* сумата на четните числа от `1` до `n`;
* сумата на нечетните числа от `1` до `n`.

## Задача 4

Създайте програма, която прочита естествено число `n` от стандартния вход и извежда на стандартния изход сумата и произведението на всички делители на числото `n`.

```
Вход: 15
Изход: 24 120
Обяснение:
    1 + 3 + 5 + 15 = 24
    1 * 3 * 5 * 15 = 120
```

## Задача 5

Създайте програма, която прочита естествено число от стандартния вход и извежда на стандартния изход дали числото е просто.

## Задача 6

Създайте програма, която прочита от стандартния вход редица от положителни числа до въвеждането на `0`. На стандартния изход изведете минимума и максимума от въведените числа.

```
Вход:
5 10 8 12 4 9 6 0

Изход:
The min is: 4
The max is: 12
```

## Задача 7

Вие сте агент от тайните служби на Мосад. Работите под прикритие в Русия. Единственият начин да комуникирате с оперативните си директори е да им изпращате кодови числа. Както знаем, на иврит се чете отдясно наляво. Създайте програма, която прочита цяло неотрицателно число `n` и проверява дали числото е `ПАЛИНДРОМ` и дали изпратеното число е валидно съобщение.

```
Вход: 1331
Изход: Valid

Вход: 1379
Изход: Invalid
```

## Задача 8

Създайте програма, която прочита от стандартния вход цяло неотрицателно число `n` и цифра `d`. На стандартния изход изведете броя на срещанията на цифрата `d` в десетичния запис на числото `n`.

## Задача 9

Създайте програма, която прочита естествено число `n` от стандартния вход и извежда на стандартния изход квадрат от `n` по `n` символа, където по главния диагонал символът е `0`, над главния диагонал символът е `+`, а под главния диагонал символът е `-`.

```
Вход: 4
Изход:

0+++
-0++
--0+
---0

```

## Задача 10

Създайте програма, която прочита размер `size` и символ `symbol`, като на стандартния изход извежда триъгълник с катети с размер `size`, изрисуван със символа `symbol`.

```
Size: 5
Character: #

#
# #
# # #
# # # #
# # # # #
```

## Задача 11

Създайте програма, която прочита от стандартния изход положително число `n` и отпечатва на стандартния изход ромб, съставен от числата до `n` включително.

```
Вход: 3
Изход:

    1
  1 2 1
1 2 3 2 1
  1 2 1
    1
```

## Задача 12

Създайте програма, която прочита от стандартния вход две положителни числа `m` и `n` и извежда на стандартния изход `n` квадрата, слепени един до друг, всеки със страна `n`.

```
Вход: 5 3
Изход:
* * * * * * * * * * * * *
*       *       *       *
*       *       *       *
*       *       *       *
* * * * * * * * * * * * *
```

## Задача 13

Създайте програма, която прочита от стандартния вход цяло неотрицателно число `n` и изведете на стандартния изход числото, записано с цифрите на числото `n`, но в обърнат ред.


### :warning: Забележки:

- Давайте смислени имена на променливите си.
- Целете се към максимално спазване на чист код.
- Не е позволено използването на мисиви.
- Винаги правете валидация на входните си данни.