/*lab1*/
/*
posiada(piotr,auto(nissan,almera)).
posiada(marcin,auto(fiat,punto)).
maAuto(X):-posiada(X,auto(_,_)).
*/

/*
lubi(jas,piernik). 
lubi(jas,malgosia).
lubi(malgosia,cukierek).
lubi(malgosia,piernik).
*/

/*
ciezszy(pomarancz,jablko).
ciezszy(jablko,mandarynka).
ciezszy(arbuz,pomarancz).
ciezszy(jablko,winogrono).
ciezszy(X,Y):-ciezszy(X,Z), ciezszy(Z,Y).
*/

/*
dog(rover).
dog(felix).
dog(benny).

animal(A):-dog(A).
*/

/*lab2*/

/*
lubi(jan, tatry).
lubi(jan, beskidy).
lubi(jerzy, beskidy).
lubi(jerzy, bieszczady).
lubi(jozef, bieszczady).
lubi(karol, beskidy).
lubi(justyna, swietokrzyskie).
bratniadusza(X, Y) :- lubi(X, S), lubi(Y, S), X \= Y.
*/
/*
wykrzyknik niezaleznie gdzie jest i tak jest false w tym swiecie;
zeby cos wypisalo to zmien jan i jerzy*/

/*
czas(t1, 120).
czas(t2, 90) .
czas(t3, 135).
dystans(t1, 9600).
dystans(t2, 8100).
dystans(t3, 13500).
predkosc(X, Ac) :- czas(X, C),dystans(X, D), Ac = D/C.
*/
/*
suma2(Z):- read(X),Z is X+6.

suma4:- read(X),read(Y), Z is sqrt(X+Y), write(Z).

suma5(X,Y,Z):- X<6, Z is X + Y.
suma5(X,Y,Z):- X=6, Z is X + Y.
*/

/*
licznik, rekurencja, kumulant
zreobic siklnie jak fivonaccii jak? nwm?? po co? nwm? zrobiE? nie ma szans
PDPDPDPDPPDPDPDPDPDPDPDPDPDPDPDPDPDPDPDPDPDPDPDPDPDPDPDPDPDPDPDPPDPDPDPDPDPDPDPDPDP
*/

/*
silnia(0,1).
silnia(N,Wynik):- N>0, N1 is N-1, silnia(N1,Wynik), Wynik is N * Wynik.
*/

/*
fib(0, 0) :- !.
fib(1, 1) :- !.
fib(N, Result) :- N > 1, N1 is N - 1, N2 is N - 2, fib(N1, R1), fib(N2, R2), Result is R1 + R2.
*/

/*
fib(1, 2).
fib(2, 3).
fib(N, Result) :- N > 1, N1 is N - 1, N2 is N - 2, fib(N1, R1), fib(N2, R2), Result is R1 + R2.

fibBU(N,X) :- fibBU(0,0,1,N,X).
fibBU(N,X,_,N,X):-!.
fibBU(N1,X1,X2,N,X) :- N2 is N1+1, X3 is X1+X2,
fibBU(N2,X2,X3,N,X).

gold(N,E,A,B) :- fib(N,R1), A is R1, fib(N-1,R2), B is R2, E is R1/R2. 
*/

/*
czyLista([]).
czyLista([_|T]) :- czyLista(T).
*/

/*
czyLista([]).
czyLista([_|T]) :- czyLista(T),write(T).
*/

czyLista([]).
czyLista([_|T]) :- write(T),czyLista(T).

ile([],0).
ile([_|T],W) :- ile(T,W1), W is W1+1.

suma([],0).
suma([H|T],W) :- suma(T,W1), W is W1+H .

#zrobić haskell do lab 5 i 6 5  do polecenia 1 lol !1!1!!!!!!!!11! (xd)