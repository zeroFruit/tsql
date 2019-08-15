# tsql

Tiny SQL engine inspired by ["Let's Build a Simple Database"](https://cstack.github.io/db_tutorial/parts/part7.html) project. Data stores using B+ trees datastructure and persistents to file.



### How to build

```
make build
```

With this one command, we can build tsql binary and you can find it in root path.



### How to run

```
./tsql <filepath>
```

tsql saves data on file and persistent so you need to specify file path.



### Tutorial

```
db > insert 1 user1 person1@example.com
Executed.
db > select
(1, user1, person1@example.com)
```




