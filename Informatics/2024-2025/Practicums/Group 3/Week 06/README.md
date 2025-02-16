# Седмица 6 - Функции и свойства на аргументите.



## Задача 1 :repeat: (Редица на Фибоначи) :repeat:

Създайте програма, която прочита от стандартния вход цяло положително число `n` и извежда на стандартния изход `n`-тото число от редицата на Фибоначи. Редицата на Фибоначи има следния вид:

> 0 1 1 2 3 5 8 13 21 ...


## Задача 2 :small_red_triangle: (Триъгълници) :small_red_triangle:

Създайте програма, която прочита от стандартния вход три реалнозначни стойности, съответстващи на страни на триъгълник. За всеки триъгълник създайте функция, която проверява или връща стойност за:

- Съществува ли триъгълник с такива страни?
- Периметъра на този триъгълник.
- Лицето на този триъгълник.

> Ако триъгълникът е равностранен, то изведете на стандартния изход и дължината на височината му, дължината на медианата му, дължината на ъглополовящата му, дължината на радиуса на описаната около триъгълника окръжност, дължината на радиуса на вписаната в триъгълника окръжност, използвайки отделна функция.

> Ако триъгълникът е правоъгълен, то изведете на стандартния изход и стойността на всеки от ъглите му, използвайки отделна функция.


## Задача 3 :calendar: (Календар) :calendar:

Създайте програма, която по въведена дата от Григорианския календар във формат DD MM YYYY извежда на стандартния изход дали стойностите на датата за ден, месец и година, са валидни.


## Задача 4 :arrows_counterclockwise: (Абсолютна Стойност) :arrows_counterclockwise:

Създайте програма, която по въведено реалнозначно число, извежда на стандартния изход абсолютната стойност на това число, но без да бъде използвана вградена функция от библиотеката `math.h`.


## Задача 5 :one: (Еднакви Цифри) :nine:

Създайте програма, която приема от стандартния вход две числа `a` и `b`, представляващи интервала `[a ; b]` и извежда на стандартния изход всички числа в интервала, които удовлетворяват условието дадено число да има съседни еднакви цифри.

```
Вход:   60 112
Изход:  66 77 88 99 100 110 111 112
```


## Задача 6 :heavy_plus_sign: (Аритметична Прогресия) :heavy_plus_sign:

Създайте програма, която приема от стандартния вход първи член на аритметична прогресия, разлика и число `n`, показващо колко елемента съдържа прогресията. Изведете на стандартния изход членовете на тази прогресия, както и сумата на членовете ѝ.


## Задача 7 :heavy_multiplication_x: (Геометрична Прогресия) :heavy_multiplication_x:

Създайте програма, която приема от стандартния вход първи член на геометрична прогресия, частно и число `n`, показващо колко елемента съдържа геометричната прогресия. Изведете на стандартния изход членовете на тази прогресия, както и сумата на членовете ѝ.


## Задача 8 :heavy_check_mark: (Каноничен Вид) :heavy_check_mark:

Създайте програма, която по въведено естествено число, извежда неговия каноничен вид. Каноничен вид на едно число е разлагането му на прости множители.

```
Вход:   2
Изход:  2

Вход:   10
Изход:  2 5

Вход:   150
Изход:  2 3 5 5
```


## Задача 9 :on: (Специални Числа) :on:

Създайте програма, която приема число от стандартния вход и извежда на стандартния изход дали всяка негова цифра в десетичния заис на числото е равна на сумата на двете цифри, намиращи се вдясно от нея.

```
Вход:   532110
Изход:  Yes

Вход:   7431
Изход:  Yes

Вход:   1379
Изход:  No
```


## Задача 10 :red_circle: (Червено и Черно) :black_circle:

*Джесика* обича цветовете червено и черно. Също така тя обича да работи и с числа. Тя е решила да даде следните наименования на цифрите:

- Червена цифра е такава, която е нечетна и се намира на нечетна позиция в записа на едно число.
- Черна цифра е такава, която е четна и се намира на четна позиция в записа на едно число.

Тя иска да направи програма, която взима поотделно червените и черните цифри на въведено от клавиатурата число и създава нови две числа, записани съответно само от червените и само от черните цифри. След това програмата трябва да вземе двете числа и да ги провери за 3 условия:

- Числото е палиндром.
- Числото има четен брой червени цифри.
- Числото има нечетен брой черни цифри.

За съжаление, *Джес* е твърде уморена след последната вечер. Помогнете ѝ, като създадете такава програма, каквато ѝ е необходима.


## Задача 11 ▲ (Триъгълник на Паскал 1) ▲

Създайте програма, която прочита от стандартния вход неотрицателно число `N` и извежда `N`-тия ред от триъгълника на Паскал на стандартния изход. Вземете предвид, че броенето в триъгълника започва от ред `0`, т.е. `N = 0` е валидна стойност.


## Задача 12 ▼ (Триъгълник на Паскал 2) ▼

Създайте програма, която прочита от стандартния вход неотрицателно число `N` и извежда всички редове до `N`-тия от триъгълника на Паскал на стандартния изход. Вземете предвид, че броенето в триъгълника започва от ред `0`, т.е. `N = 0` е валидна стойност.


## Задача 13 𖤐 (Формула на Нютон) 𖤐

Създайте програма, която прочита от стандартния вход цяло число `N` и извежда на стандартния изход развитието на формулата $(a + b)^{N}$. Вземете предвид всички възможни стойности на числото `N`.
