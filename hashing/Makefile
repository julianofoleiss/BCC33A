all:
	gcc -g -c ilist.c
	gcc -g ilist_test.c -o ilist_test ilist.o
	gcc -g -c hashtable_ed.c
	gcc -g -c prime_list.c
	gcc -g -c hashtable_ea.c
	gcc -g prime_list_test.c -o prime_list_test prime_list.o
	gcc -g -c utils.c
	gcc -g embaralhar_test.c -o embaralhar_test utils.o
	gcc -g main.c -o main ilist.o prime_list.o hashtable_ea.o utils.o
