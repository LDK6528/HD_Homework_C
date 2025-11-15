#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_TASKS 100
#define MAX_LENGTH 100
#define FILENAME "todo_list.txt"
typedefstruct{
char task[MAX_LENGTH];  
intcompleted;          
 char date[11];         
} Task;
Task tasks[MAX_TASKS];
inttask_count = 0;


void loadTasks() {
	FILE* file = fopen(FILENAME, "r");
	if (file == NULL) return;
	while (fscanf(file, "%d %10s %[^\n]", &tasks[task_count].completed,
		tasks[task_count].date, tasks[task_count].task) == 3) {
		task_count++;
	}
	fclose(file);
}

void saveTasks() {
	FILE* file = fopen(FILENAME, "w");
	if (file == NULL) {
		printf("파일저장오류!\n");
		return;
	}
	for (inti = 0; i < task_count; i++) {
		fprintf(file, "%d %s %s\n", tasks[i].completed, tasks[i].date, tasks[i].task);
	}
	fclose(file);
}

void addTask() {
	if (task_count >= MAX_TASKS) {
		printf("더이상할일을추가할수없습니다.\n");
		return;
	}
	getchar();  // 이전입력의개행문자제거
	printf("새로운할일: ");
	fgets(tasks[task_count].task, MAX_LENGTH, stdin);
	tasks[task_count].task[strcspn(tasks[task_count].task, "\n")] = '\0';  // 개행문자제거
	printf("완료날짜(YYYY-MM-DD): ");
	scanf("%10s", tasks[task_count].date);
	tasks[task_count].completed = 0;  // 기본적으로미완료상태
	task_count++;
	printf("할일이추가되었습니다!\n");
}


void deleteTask() {
	intnum;
	displayTasks();
	if (task_count == 0) return;
	printf("삭제할할일번호:");
	scanf("%d", &num);
	if (num< 1 || num> task_count) {
		printf("잘못된번호입니다.\n");
		return;
	}
	for (inti = num - 1; i < task_count - 1; i++) {
		tasks[i] = tasks[i + 1];
	}
	task_count--;
	printf("할일이삭제되었습니다!\n");
}


void displayTasks() {
	if (task_count == 0) {
		printf("할일이없습니다!\n");
		return;
	}
	printf("\nTODOlist:\n");
	for (inti = 0; i < task_count; i++) {
		printf("%d. [%s] %s (완료기한: %s)\n",
			i + 1,
			tasks[i].completed ? "X" : " ",
			tasks[i].task,
			tasks[i].date);
	}
}


void completeTask() {
	intnum;
	displayTasks();
	if (task_count == 0) return;
	printf("완료할할일번호: "); //완료할할일번호
	scanf("%d", &num);
	if (num< 1 || num> task_count) {
		printf("잘못된번호입니다.\n");
		return;
	}
	tasks[num - 1].completed = 1;
	printf("할일이완료되었습니다!\n"); //할일완료
}

int main() {
	intchoice;
	loadTasks();  // 시작시파일에서불러오기
	while (1) {
		printf("\n===== TODO list =====\n");
		printf("1. 할일추가\n");
		printf("2. 할일삭제\n");
		printf("3. 목록보기\n");
		printf("4. 완료체크\n");
		printf("5. 종료\n");
		printf("선택: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			addTask();
			break;
		case 2:
			deleteTask();
			break;
		case 3:
			displayTasks();
			break;
		case 4:
			completeTask();
			break;