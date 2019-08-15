build: src/main.c
	gcc src/row.c src/btree.c src/table.c src/compiler.c src/vm.c src/main.c -o tsql

run: tsql
	./tsql

clean:
	rm -f tsql

test: tsql
	bundle exec rspec --format doc test/main_test.rb

format: *.c
	clang-format -style=Google -i *.c