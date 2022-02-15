# Comandos de map

- [Iniciar o mapa](#Iniciar-um-map)
- [Inserir um elemento no map](#Inserir-um-elemento-no-map)
- [Remover um elemento do map](#Remover-um-elemento-do-map)
- [Imprimir um map](#Imprimir-um-map)
- [Procurar um elemento no map](#Procurar-um-elemento-no-map)
- [Verificar se um elemento existe no map](#Verificar-se-um-elemento-existe-no-map)

## Nome da biblioteca:
```c++
#include <map>
```

---


## Iniciar um map
```c++
//map<chave, valor>
map<type1, type2> name_map;
```
exemplo:
```c++
map<int, string> mapa;
```

---


## Inserir um elemento no map
### Modo não usual
```c++
mapa[chave] = valor;
```
exemplo:
```c++
map<int, string> mapa;

mapa[0] = "mouse";
mapa[1] = "teclado";
mapa[2] = "monitor";

// mapa = {0: "mouse", 1: "teclado", 2: "monitor"}
```

### Modo usual
```c++	
mapa.insert(pair<int, string>(chave, valor));
```
exemplo:
```c++
// precisa de um pair
map<int, string> mapa;

mapa.insert(pair<int, string>(0, "mouse"));
mapa.insert(pair<int, string>(1, "teclado"));
mapa.insert(pair<int, string>(2, "monitor"));

// mapa = {0: "mouse", 1: "teclado", 2: "monitor"}
```

---


## Removendo elementos do map
### Remover um elemento do map
```c++
mapa.erase(chave);
```
exemplo:
```c++
map<int, string> mapa;

mapa.insert(pair<int, string>(0, "mouse"));
mapa.insert(pair<int, string>(1, "teclado"));
mapa.insert(pair<int, string>(2, "monitor"));

// mapa = {0: "mouse", 1: "teclado", 2: "monitor"}


mapa.erase(1); //passa a CHAVE como referencia

// mapa = {0: "mouse", 2: "monitor"}

```


### Retirar um intervalo de elementos do map
```c++
mapa.erase(chave_inicial, chave_final);
```
exemplo:
```c++	
map<int, string> mapa;

mapa.insert(pair<int, string>(0, "mouse"));
mapa.insert(pair<int, string>(1, "teclado"));
mapa.insert(pair<int, string>(2, "monitor"));
mapa.insert(pair<int, string>(3, "Gabinete"));
mapa.insert(pair<int, string>(4, "HD"));

// mapa = {0: "mouse", 1: "teclado", 2: "monitor", 3: "Gabinete", 4: "HD"}

// retira os elementos da chave 0 até a chave 2
mapa.erase(mapa.begin(), mapa.find(3));

//mapa = {2: "monitor", 3: "Gabinete", 4: "HD"}

```

### Remover todos os elementos do map
```c++
mapa.clear();
```
exemplo:
```c++
map<int, string> mapa;

mapa.insert(pair<int, string>(0, "mouse"));
mapa.insert(pair<int, string>(1, "teclado"));
mapa.insert(pair<int, string>(2, "monitor"));

// mapa = {0: "mouse", 1: "teclado", 2: "monitor"}

mapa.clear();

// mapa = {}
```
---


## Procurar um elemento no map
```c++
//retorna um iterador
mapa.find(chave);
```
Exemplo:
```c++
map<int, string> mapa;

mapa.insert(pair<int, string>(0, "mouse"));
mapa.insert(pair<int, string>(1, "teclado"));
mapa.insert(pair<int, string>(2, "monitor"));

map<int, string>::iterator it;

it = mapa.find(1);
// it = mapa[1]
// se não existir, it = mapa.end()
```


---


## Verificar se um elemento existe no map
### Disponível apenas no C++20
```c++
mapa.count(chave);
```
ex:
```c++
    map<int, string> mapa;
    map<int, string>::iterator it;

    mapa[1] = "mouse";
    mapa[2] = "teclado";
    mapa[3] = "monitor";

    // retorna 1 se a chave for encontrada
    cout << mapa.contains(1) << endl;
```



## Imprimir um map
### Chave do type int
```c++
map<int, string> mapa;

mapa[1] = "mouse";
mapa[2] = "teclado";
mapa[3] = "monitor";

for(int i{0}; i < 3; i++) {
    cout << mapa[i] << endl;
}
```

### Com iterator imprimindo a chave
```c++
map<int, string> mapa;

map<int, string>::iterator it;

mapa[1] = "mouse";
mapa[2] = "teclado";
mapa[3] = "monitor";

for(it = mapa.begin(); it != mapa.end(); it++) {
    cout << it->first << endl;
}
```
### Com iterator imprimindo o valor
```c++
map<int, string> mapa;
map<int, string>::iterator it;

mapa[1] = "mouse";
mapa[2] = "teclado";
mapa[3] = "monitor";

for(it = mapa.begin(); it != mapa.end(); it++) {
    cout << it->second << endl;
}
```





