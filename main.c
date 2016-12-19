#include "Header.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE *f = fopen("data.d", "r");
	time_t rawtime;
	struct tm * timeinfo;
	if (f == NULL) {
		char s[22];
		char buffer[80];
		int c;
		FILE *f = fopen("data.d", "w");

		printf("Введи от какой привычки ты бы хотел избваиьтся. Напр. 'дрочить' макс 20 символов\n");
		scanf("%s", s);
		c = strlen(s);
		s[c] = '\n';
		s[c + 1] = '\0';
		fputs(s, f);

		
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(buffer, 80, "%y %m %d %H %M %S", timeinfo);
		fputs(buffer, f);
		fclose(f);
	}
	else {

		fclose(f);
	}
	FILE *fr = fopen("data.d", "r");
		char s[22];
		fgets(s, 22, fr);
		int d = strlen(s);
		s[d - 1] = '\0';
		char buf[3];
		buf[2] = '\0';
		int ti[6];
		int i = 0;
		int t = 0;
		while (i < 6) {
			buf[t] = fgetc(fr);
			if (buf[t] != ' ') {
				t++;
			}

			if (t == 2) {

				ti[i] = atoi(buf);
				t = 0;
				i++;
			}


		}
		//
		fclose(fr);
		system("cls");
		int ti2[6];
		while (1) {
			char buffer[80];
			time(&rawtime);
			timeinfo = localtime(&rawtime);
			printf("Я перестал %s от %d.%d.20%d %d:%d:%d\n", s, ti[2], ti[1], ti[0], ti[3], ti[4], ti[5]);
			strftime(buffer, 80, "%y %m %d %H %M %S", timeinfo);
			i = 0;
			t = 0;
			int b = 0;
			while (i < 6) {
				buf[t] = buffer[b];
				b++;
				if (buf[t] != ' ') {
					t++;
				}

				if (t == 2) {

					ti2[i] = atoi(buf);
					t = 0;
					i++;
				}


			}
			timech(ti,ti2);
			printf("С этого момента прошло %d лет %d месяцев %d дней %d часов %d минут %d секунд\n", ti2[2], ti2[1], ti2[0], ti2[3], ti2[4], ti2[5]);
			printf("Что бы обнулить дату, удали файл 'data.d'\nПрогу специально написал для Антона Антонова");
			Sleep(2000);
			system("cls");
			
		}
	
	return 0;
}


void timech(int *t1, int *t2) {

	for (int i = 6;i>=0;i--) {
		t2[i] = t2[i] - t1[i];
		if (t2[i] < 0) {
			t2[i] = 60 + t2[i];
			t2[i - 1]--;
		}


	}

}
