**WORK IN POGRESS**

# Algorithmique : explications et codes.


## Avant-propos

Ce repo est là pour renseigner différents algorithmes, aussi bien pour traiter des données (via les piles, tableaux, arbres, listes chaînées...) que pour trier ou effectuer des opérations diverses. Je ne suis ni mathématicien, ni informaticien, il faut donc prendre ce que j'écris avec un point de vue critique.

De façon générale, il s'agit plus pour moi de coucher sur papier ce que je comprends du sujet et de mettre en pratique cette compréhension par l'explication d'une problématique et sa mise en oeuvre concrète dans un code.

Ce dépo va considérablement changer au fur et à mesure de la résolution et présentations de différents exercices / algo.

Il est rédigé principalement avec l'aide du livre "Algorithmique en C, C++, Java et Python".

L'ensemble du code sera écrit en C.

## La notion de complexité

La notion de complexité algorithmique peut-être difficile à appréhender. En effet, alors qu'en mathématiques sur papier le calcul n'est pas vraiment fait, entendu par là que faire est l'obtention d'un résultat (on ne calcule par nécessairement le résultat d'une équation mais on écrit systématiquement sa forme générale), en informatique, il faut faire en sorte qu'une (des) instruction(s) donne un résultat et que les opérations qui servent à déterminer ce résultat soient réellement faites, et ceci dans un temps plus ou moins longs mais humainement plausible (ou non) selon la tâche donnée.

Ce que nous souhaitons exprimer par là, c'est que si une opération est écrite, c'est qu'elle doit donner un résultat dans un temps qu'il est possible de se figurer. Un programme informatique étant différent dans son écriture qu'une formule mathématique, on va chercher à penser la durée d'exécution de ce programme via ce qu'on nomme la complexité. La complexité est directement rattachée au nombres d'instructions - de calculs - qu'un ordinateur devra oéprer afin d'arriver au résultat demandé.

Il y a deux façons d'analyser cette complexité :

- L'analyse moyenne de la complexité. Elle consiste à analyser le temps moyen de calcul pour un problème donné.

- L'analyse pessimiste de la complexité. Elle consiste à analyser le pire des cas - en temps de calcul (d'opérations à faire) concernant un problème donné.

Cette dernière méthode est celle qui est privilégiée. En effet, il est toujours plus judicieux de penser au pire des cas possible. Tandis qu'une analyse moyenne de la complexité ne peut pas prendre en compte le cas le plus extrême et donc réserver une mauvaise surprise [^1], la vision pessimiste permet d'écarter cette effet en montrant directement ce cas le plus extrême.

## Présentation de l'analyse pessimiste de la complexité

COnsidérons une liste de 100 données quelconques parmi lesquelles il faut en trouver une seule. Dans le cadre de l'analyse pessimiste, on notera comme suit :

`O(N)`

Où "O" indique que l'analyse porte sur la limite supérieure des données à analyser et "N" correspond au nombre d'éléments à analyser.

## Les familles de complexité

**=>** Les algorithmes logarithmiques : `O(log2(N))`

COmme le montre assez clairement la représentation ci-dessus, la complexité dans le pire des cas sera du logarithme du nombre N d'éléments à analyser, ce qui en fait sans conteste d'un algorithme extrêmement rapide. A titre d'exemple, pour 10 000 données à traiter s'il s'agit d'un algorithme logarithmique, il faudra au pire des cas 4 instructions si on considère un logarithme en base 10 (log10(N)) alors qu'un algo linéaire (O(N)) il en faudrait 10 000. Concernant les algorithmes qui nous intéressent, le logarithme est en base 2, car les algorithmes logarithmiques opèrent généralement des divisions par 2 succesives du tas de données à traiter jusque trouver la donnée souhaitée. Ainsi, pour 10 000 données :

`O(log2(10 000) = 13,28771238`  instructions dans le pire des cas.

**=>** Les algorithmes linéraires : `O(N)`

La complexité dépend de façon linéaire au nombre de données à calculer. Ainsi pour 10 000 et une complexité de 0(N) :

`0(10 000) = 10 000` instructions dans le pire des cas.

**=>** Les algorithmes linéraires et logarithmiques : `O(N log2(N))`

Ce sont des algorithme qui divisent successivement les données par deux et parcourent le tas ainsi divisé de façon complète.

`O(10 000 * log2(10 000)) = 132877,123795494` opérations dans le pire des cas.

**=>** Les algorithmes quadratiques : `O(N²)`

Pour 10 000 :

`O(10 000²) = 100 000 000` (100 millions) d'opérations dans le pire des cas.

**=>** Les algorithmes exponentiels : `O(e^N)`

Un type d'algorithme au temp de calcul invraisemblable. Le nombre de calculs augmente de façon exponentielle. Pour 100 données initiales (plus est incalculable avec notre ordinateur) :

`O(e^100) = 2,688117142×10⁴³` calculs dans le pire des cas (!!).

**=>** Les algorithmes Factoriels : `O(N!)`

Même remarque pour les algorithmes exponentiels, mais en pire. Pour 100 données initiales :

`O(100!) = 9,332621544×10¹⁵⁷` calculs dans le pire des cas (!!!!).

Ces deux derniers types d'algorithmes produisent des résultats, mais dans un temps indéterminé : ils sont dits "incalculables". Ce sont des algorithmes extrêmement complexes qui opèrent dans les sphères de l'intelligence artificielles, de la programmation de systèmes très complexes liés à des organes qui le sont tout autant, les modélisations météorologiques etc.

[^1] : Le propre d'une moyenne est d'être une représentation archétypale mais pas nécessaire d'un ensemble de données. Si pour une donnée à trouver parmi 100 données la moyenne est de 50 instructions à opérer (O(N / 2)), cela ne veut pas dire qu'à tous les coups il y aura 50 instructions d'opérées. Dans l'optique d'une analyse pessimiste, nous aurions N instructions à faire, N correspondant au nombre maximal de données à analyser (O(N)).
