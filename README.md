# BallsAndBinsSimulation
Symulacja losowania kul do urn i grafy z pobranych statystyk

Jednym z klasycznych modeli probabilistycznych, czesto rozwazanym w kontekscie zagadnien algorytmicznych, jest model kul
i urn (ang. balls and bins). W modelu tym m kul wrzucanych jest kolejno do n ­1 ponumerowanych urn. 
Kazda kula wrzucana jest niezaleznie z jednakowym prawdopodobienstwem
 równym 1 przez n do jednej z urn.

 Wrzucenie m kul do n urn w taki sposób mozemy utozsamiac
z losowa funkcja ze zbioru {1, . . . , m} w zbiór {1, . . . , n} (formalnie, przestrzenia zdarzen
elementarnych jest wówczas zbiór Ωn,m = {1, . . . , n}
{1,...,m}
).

Celem tego zadania jest eksperymentalne wyznaczenie nastepujacych wielkosci: 

(a) Bn – moment pierwszej kolizji; Bn = k, jesli  k-ta z wrzucanych kul jest pierwsza, która
trafiła do niepustej urny (paradoks urodzinowy, ang. birthday paradox),

(b) Un – liczba pustych urn po wrzuceniu n kul,

(c) Ln – maksymalna liczba kul w urnie po wrzuceniu n kul (maximum load),

(d) Cn – minimalna liczba rzutów, po której w kazdej z urn jest co najmniej jedna kula 
(pierwszy moment, po którym nie ma juz pustych urn; problem kolekcjonera kuponów, ang. coupon collector’s problem),

(e) Dn – minimalna liczba rzutów, po której w kazdej z urn sa co najmniej dwie kule ( the
siblings of the coupon collector / coupon collector’s brother),

(f) Dn −Cn – liczba rzutów od momentu Cn potrzeba do tego, zeby w kazdej urnie były co ˙
najmniej dwie kule.
