#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Question{
    char text[20];
    int correct;
    int user;
};
void print_menu()
{
    printf("1.) practice\n");
    printf("2.) Test\n");
    printf("3,) Exit\n");
}
void response_right_answer()
{
    const char *right_res[] = {"Very good!"," Excellent!", "Nice work!", "Well done!", "Great!", "Keep up the good work!" };
    int n = sizeof(right_res) / sizeof(right_res[0]);
    int idx = rand() % n;
    printf("%s\n", right_res[idx]);
}
void response_wrong_answer()
{
    const char *wrong_res[] = {"No. Please try again" ,"Wrong. Try once again." ,"Don’t give up!" ,"No. Keep trying." ,"Sorry, it is not right"};
    int n = sizeof(wrong_res)/sizeof(wrong_res[0]);
    int i = rand()%n;
    printf("%s\n",wrong_res[i]);
}
void add()
{
    int sum,a,b,answer;
    for (int i=1;i<=10;i++)
    {
        do{
        a= rand()%100;
        b= rand()%100;
        sum = a+b;
        }while(sum>100);
        while(1)
        {
            printf("Q%d %d + %d = ",i,a,b);
            scanf("%d",&answer);
            if (answer == sum)
            {
            response_right_answer();
            break;
            }else
            {
            response_wrong_answer();
            }
    }
    }

}
void sub()
{
    int sub,a,b,answer;
    for (int i=1;i<=10;i++)
    {
        do{
        a= rand()%100;
        b= rand()%100;
        }while(a<b);
        sub = a-b;
        while(1){
            printf("Q%d %d - %d = ",i,a,b);
            scanf("%d",&answer);
            if (answer == sub)
            {
            response_right_answer();
            break;
            }else
            {
            response_wrong_answer();
            }
    }
}
}
void mix()
{
   int a,b,sum,sub,answer;
   for(int i = 0; i<=10;i++)
    {
    do{
        a = rand()%100;
        b = rand()%(100);
        sum = a+b;
        sub = a-b;
      }while(sum>=100 || a<b);
      if (sum <100 && rand()%2 == 0)
      {
        while(1)
        {
            printf("Q%d %d + %d = ",i,a,b);
            scanf("%d",&answer);
            if (answer == sum)
            {
            response_right_answer();
            break;
            }else
            {
            response_wrong_answer();
            }
        }
      }else
      {
            while(1){
                printf("Q%d %d - %d = ",i,a,b);
                scanf("%d",&answer);
            if (answer == sub)
            {
                response_right_answer();
                break;
            }else
            {
                response_wrong_answer();
            }
    }
      }

}
}
void practice()
{
    int choice;
    printf("1) ADD\n");
    printf("2) Subtraction\n");
    printf("3) ADD and SUB mixed\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (choice == 1) {
        add();
    } else if (choice == 2) {
        sub();
    } else if (choice == 3) {
        mix();
    } else {
        printf("Invalid choice.\n");
    }
}
void add_test(struct Question quiz[], int i) {
    int a, b, sum;
    do {
        a = rand() % 100;
        b = rand() % (100 - a);
        sum = a + b;
    } while (sum >= 100);

    quiz[i].correct = sum;
    snprintf(quiz[i].text, sizeof(quiz[i].text), "%d + %d", a, b);
}


void sub_test(struct Question quiz[], int i) {
    int a, b;
    do {
        a = rand() % 100;
        b = rand() % 100;
    } while (a < b);

    quiz[i].correct = a - b;
    snprintf(quiz[i].text, sizeof(quiz[i].text), "%d - %d", a, b);
}

void test() {
    struct Question quiz[15];
    int score = 0;

    srand(time(NULL));

    for (int i = 0; i < 15; i++)
    {
        if (rand() % 2 == 0)
        {
            add_test(quiz, i);
        } else
        {
            sub_test(quiz, i);
        }

        printf("Q%d: %s = ", i + 1, quiz[i].text);
        scanf("%d", &quiz[i].user);

        if (quiz[i].user == quiz[i].correct)
        {
            score++;
        }
    }

    float percentage = ((float)score / 15.0) * 100.0;
    printf("Your test result is %.2f%%\n", percentage);
    printf("Detailed questions and answers:\n");
    printf("Nr    Question      Correct answer    Your answer\n");
    for (int i = 0; i < 15; i++) {
        printf("%2d   %10s   %10d   %10d\n",
               i + 1, quiz[i].text, quiz[i].correct, quiz[i].user);
    }
}

void main(void)
{
    int c;
    char name[15];
    printf("Welcome!!! please Enter your name: ");
    scanf("%s",&name);
    srand(time(NULL));
    while (1)
    {
        print_menu();
        printf("Enter you choice: \n");
        scanf("%d",&c);

        if (c == 3)
        {
         break;
        }
        if(c == 1)
        {
            practice();
        }
        if(c == 2)
        {
            test();
        }
    }
}
