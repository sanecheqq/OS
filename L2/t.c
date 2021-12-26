#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>


void my_print(char str[1024]) {
	for(int i = 0; str[i] != '\0'; i++) {
		write(1, &str[i], sizeof(char));
	}
}


void my_read_int(int* a) {
	int res = 0, i = 1;
	char c;
	read(0, &c, sizeof(char));
	while(c != '\n' && c != EOF) {
		if (c < '0' || c > '9') {
				my_print("Incorrect input\n");
				return;
			}
		res = res*10 + (c -'0');
		read(0, &c, sizeof(char));
		printf("res = %d\n", res);	
	}
	*a = res;
}



int reverse(int x) {
	int res = 0;
	while (x > 0) {
		int a = x % 10;
		res = res*10 + a;
		x /= 10;
	}
	return res;
}

void print_num(int a) {
	char* num;
	if (a == 0) num = "0";
	if (a == 1) num = "1";
	if (a == 2) num = "2";
	if (a == 3) num = "3";
	if (a == 4) num = "4";
	if (a == 5) num = "5";
	if (a == 6) num = "6";
	if (a == 7) num = "7";
	if (a == 8) num = "8";
	if (a == 9) num = "9";
	write(1, num, sizeof(char));
}

void print_val(float x) {
	float left;
	float right = modff(x, &left);

	//вывод целой части
	left = reverse(left);
	int l = left;
	while(l > 0) {
		print_num(l%10);
		l /= 10;
	}
	write(1, ".", sizeof(char));

	//вывод дробной часи
	int i = 0;
	while (right > 0) { //0,456
		float new = right*10; //4,56
		right = right*10;
		while (right > 1) right--; // по итогу right = 0,56
		float for_print = new - right; // 4,56 - 0,56
		print_num(for_print); // вывод цифры 4
		//повтор цикла для 0,56 и тд
		i++;
		if (i == 5) {
			printf("\n%f\n", right);
			break; 
		} 
	}
}

void print_int(int x) {
	x = reverse(x);
	if (x == 0) {
		print_num(x);
	}
	while(x > 0) {
		print_num(x%10);
		x /= 10;
	}
}
///////////////
///////////////////////////////////////////// ПОЧИНИТЬ РЕВЕРС ДЛЯ СЛУЧАЯ ЕСЛИ НА КОНЦЕ ЕСТЬ НУЛИ И ДОДЕЛАТЬ ВВОД ЧИСЛА ЛИНИЙ И ВЫВОД ПИДА РЕБЕНКА
int main() {
	int x = 0;
	my_read_int(&x);
	printf("%d", x);

/*
	char* num;
	int a = 1;
	if (a == 1) num = "1";
	if (a == 2) num = "2";
	if (a == 3) num = "3";

	write(1, num, sizeof(char));*/
}

