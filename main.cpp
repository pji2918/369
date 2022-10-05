#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <time.h>
#include <windows.h>
//#include <ctype.h>
#include <unistd.h>
#define _CRT_SECURE_NO_WARNINGS

/*
Copyright (C) 2022 pji2918

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

int player;
FILE *fp = fopen("data.sav", "r");
int max = 0;
int mode = 0;

// 세이브 데이터 삭제 //
void Remove()
{
    SetConsoleTitle(TEXT("369 게임 - 데이터 삭제"));
    char y;
    system("cls");
    printf("정말로 삭제하시겠습니까?");
    printf("\n입력: "), scanf(" %c", &y);
    if (y == 'y')
    {
        system("cls");
        fclose(fp);
        system("del data.sav /q");
        system("cls");
        printf("모든 데이터를 삭제했습니다.\n");
        max = 0;
        system("pause");
    }
    else
    {
        system("cls");
    }
}

// 싱글플레이 게임 //
void SinglePlayGame()
{
    system("cls");
    // 초기 값 설정 //
    int a = 1;
    int wrong = 0;
    int g = 0;
    int cheat = 0;
    // 게임 메인 폼 //
    while (1)
    {
        if (mode == 1)
        {
            printf("현재 숫자는 %d 입니다.", a);
        }
        else
        {
            printf("어려움 모드는 숫자를 보여주지 않습니다.");
        }
        printf("\n숫자라면 0, 박수라면 1을 입력하세요.");
        printf("\n입력: "), scanf("%d", &g);
        if (a % 3 == 0 && a != 1)
        {
            // switch문으로 입력값 처리 //
            switch (g)
            {
            case 0:
                // 틀릴 경우 //
                system("cls");
                printf("틀렸습니다! %d은/는 3의 배수였습니다.", a);
                wrong = 1;
                break;
            case 1:
                // 맞을 경우 //
                printf("\n정답입니다!");
                a++;
                break;
            case 780714:
                // 치트 //
                system("cls");
                printf("치트 활성화! 점프할 값을 입력하세요. "), scanf("%d", &a);
                continue;
            default:
                // 0, 1 또는 치트가 아닌 경우 //
                system("cls");
                printf("올바르지 않은 값입니다.");
                wrong = 1;
                break;
            }
        }
        else if (a % 10 == 3 || a % 30 == 0 || a % 100 / 10 == 3 && a != 1)
        {
            switch (g)
            {
            case 0:
                // 틀릴 경우 //
                system("cls");
                printf("틀렸습니다! %d에는 3이 포함되어 있었습니다.", a);
                wrong = 1;
                break;
            case 1:
                // 맞을 경우 //
                printf("\n정답입니다!");
                a++;
                break;
            case 780714:
                // 치트 //
                system("cls");
                printf("치트 활성화! 점프할 값을 입력하세요. "), scanf("%d", &a);
                system("cls");
                continue;
                break;
            default:
                // 1, 2, 치트가 아닌 경우 //
                system("cls");
                printf("올바르지 않은 값입니다.");
                wrong = 1;
                break;
            }
        }
        else
        {
            // 윗 코드와 같음 //
            switch (g)
            {
            case 0:
                printf("\n정답입니다!");
                a++;
                break;

            case 1:
                system("cls");
                printf("틀렸습니다! %d은/는 3의 배수가 아니었습니다.", a);
                wrong = 1;
                break;
            case 780714:
                system("cls");
                printf("치트 활성화! 점프할 값을 입력하세요. "), scanf("%d", &a);
                system("cls");
                continue;
            default:
                system("cls");
                printf("올바르지 않은 값입니다.");
                wrong = 1;
                break;
            }
        }
        if (wrong == 1)
        {
            char retry = 'n';
            // 패배 //
            printf("\n게임에서 패배했습니다.");
            if (a > max)
            {
                // 최고 기록 달성 시 데이터 기록 //
                FILE *fp = fopen("data.sav", "w");
                fprintf(fp, "%d", a);
                max = a;
                printf("\n최고 기록을 세웠습니다!\n기록을 저장했습니다.");
                fclose(fp);
            }
            a = 1;
            wrong = 0;
            g = 0;
            cheat = 0;
            printf("\n다시 플레이하시겠습니까?");
            printf("\n입력: "), scanf(" %c", &retry);
            if (retry == 'y')
            {
                a = 1;
                system("cls");
                continue;
            }
            else
            {
                return;
            }
        }
        else
        {
            if (a >= 100)
            {
                // 게임 승리 시 메시지 출력 및 데이터 기록 //
                system("cls");
                FILE *fp = fopen("data.sav", "w");
                fprintf(fp, "100");
                printf("축하합니다. 100을 달성하여 게임에서 승리했습니다.");
                printf("\n진심으로 축하드립니다.");
                printf("\n클리어 기록을 저장했습니다.");
                printf("\n제작: pji2918\n");
                system("pause");
                break;
            }

            // 계속 게임 진행 //

            printf("\n잘 입력했습니다. 게임이 계속 진행됩니다.\n\n");
        }
    }
}

// 싱글플레이 메뉴 //
void SinglePlay()
{
    // 모드 선택 //
    int f = 0;
    while (f == 0)
    {
        SetConsoleTitle(TEXT("369 게임 - 싱글플레이"));
        mode = 0;
        char fuck[100] = {0};
        system("cls");
        printf("============ 싱글플레이 모드 ============");
        printf("\n============== 난이도 선택 ==============");
        printf("\n 1 | 일반: 일반적인 369 게임입니다.\n 2 | 어려움: 숫자를 보여주지 않습니다.\n 3 | 뒤로 가기");
        printf("\n=========================================");
        if (max >= 100)
        {
            printf("\n\t    최고 기록: CLEAR");
        }
        else if (max == 0)
        {
            printf("\n\t ----- 데이터 없음 -----");
        }
        else
        {
            printf("\n\t      최고 기록: %d", max);
        }
        printf("\n=========================================");
        printf("\n입력: "), scanf("%d", &mode);
        if (mode == 3)
        {
            return;
        }
        else if (mode == 1 || mode == 2)
        {
            SinglePlayGame();
            continue;
        }
        // EASTER EGG //
        else if (mode == 18)
        {
            system("cls");
            getc(stdin);
            gets(fuck);
            if (strcmp(fuck, "181818181818181818181818181818181818") == 0)
            {
                system("start https://youtu.be/dQw4w9WgXcQ");
                exit(0);
            }
            else if (strcmp(fuck, "U.R.F.") == 0)
            {
                system("start https://youtu.be/qYIiy03eGE0");
                exit(0);
            }
            else if (strcmp(fuck, "Awesome") == 0)
            {
                system("start https://youtu.be/oLTrNq2MnBM");
                exit(0);
            }
            else if (strcmp(fuck, "pji2918") == 0)
            {
                system("start https://w.namu.la/s/392c8d0ac28ce9c7f5e353d0b1585e2ac3055ff2bd6f645cb00ec231c01b8876f9aeb8a54cf9fe38da0e61ae346e056ffa02c5b6c435167083189ced5a301bccd134bc5a918fb54fc3c7336c08ca8abfda342651c27e78e10273beeb41399b2728c47cc6c7153147340e43371027e6e8");
                exit(0);
            }
            else
            {
                exit(0);
            }
        }
        else if (mode == 0)
        {
            continue;
        }
        // 1, 2, 3이 아닌 경우 일반 모드로 진행 //
        else if (mode != 1 && mode != 2 && mode != 18)
        {
            printf("1 또는 2가 아닙니다. 일반 모드로 게임을 진행합니다.\n");
            mode = 1;
            system("pause");
            SinglePlayGame();
        }
    }
}

// 멀티플레이 게임 //
void MultiPlayGame()
{
    system("cls");
    // 초기 값 설정 //
    int a = 1;
    int wrong = 0;
    int g = 0;
    int cheat = 0;
    int count = 0;
    int turn = 1;
    int die[player + 1] = {0};
    // 게임 메인 폼 //
    while (1)
    {
        if (count == player - 1)
        {
            while (die[turn] == 1 && turn <= player)
            {
                turn++;
                if (turn == player)
                {
                    turn = 1;
                }
            }

            system("cls");
            printf("%d번째 플레이어가 승리했습니다!", turn);
            printf("\n마지막 숫자는 %d였습니다.", a);
            printf("\n플레이해주셔서 감사합니다!");
            system("pause");
            break;
        }
        while (die[turn] == 1 && turn <= player)
        {
            turn++;
            if (turn == player)
            {
                turn = 1;
            }
        }
        if (a == 100)
        {
            system("cls");
            printf("%d번째 플레이어가 100을 달성하여 승리했습니다!", turn);
            printf("\n플레이해주셔서 감사합니다!");
            system("pause");
            break;
        }
        printf("%d번째 플레이어의 차례입니다.", turn);
        if (mode == 1)
        {
            printf("\n현재 숫자는 %d 입니다.", a);
        }
        else
        {
            printf("\n어려움 모드는 숫자를 보여주지 않습니다.");
        }
        printf("\n숫자라면 0, 박수라면 1을 입력하세요.");
        printf("\n입력: "), scanf("%d", &g);
        if (a % 3 == 0 && a != 1)
        {
            // switch문으로 입력값 처리 //
            switch (g)
            {
            case 0:
                // 틀릴 경우 //
                system("cls");
                printf("틀렸습니다! %d은/는 3의 배수였습니다.", a);
                wrong = 1;
                break;
            case 1:
                // 맞을 경우 //
                printf("\n정답입니다!");
                a++;
                break;
            case 780714:
                // 치트 //
                system("cls");
                printf("치트 활성화! 점프할 값을 입력하세요. "), scanf("%d", &a);
                continue;
            default:
                // 0, 1 또는 치트가 아닌 경우 //
                system("cls");
                printf("올바르지 않은 값입니다.");
                wrong = 1;
                break;
            }
        }
        else if (a % 10 == 3 || a % 30 == 0 || a % 100 / 10 == 3 && a != 1)
        {
            switch (g)
            {
            case 0:
                // 틀릴 경우 //
                system("cls");
                printf("틀렸습니다! %d에는 3이 포함되어 있었습니다.", a);
                wrong = 1;
                break;
            case 1:
                // 맞을 경우 //
                printf("\n정답입니다!");
                a++;
                break;
            case 780714:
                // 치트 //
                system("cls");
                printf("치트 활성화! 점프할 값을 입력하세요. "), scanf("%d", &a);
                system("cls");
                continue;
                break;
            default:
                // 1, 2, 치트가 아닌 경우 //
                system("cls");
                printf("올바르지 않은 값입니다.");
                wrong = 1;
                break;
            }
        }
        else
        {
            // 윗 코드와 같음 //
            switch (g)
            {
            case 0:
                printf("\n정답입니다!");
                a++;
                break;

            case 1:
                system("cls");
                printf("틀렸습니다! %d은/는 3의 배수가 아니었습니다.", a);
                wrong = 1;
                break;
            case 780714:
                system("cls");
                printf("치트 활성화! 점프할 값을 입력하세요. "), scanf("%d", &a);
                system("cls");
                continue;
            default:
                system("cls");
                printf("올바르지 않은 값입니다.");
                wrong = 1;
                break;
            }
        }
        if (wrong == 1)
        {
            // 패배 //
            printf("\n%d번째 플레이어가 탈락했습니다.\n", turn);
            wrong = 0;
            count++;
            die[turn] = 1;
            ++turn;
            if (turn > player)
            {
                turn = 1;
            }
            continue;
        }
        else
        {

            // 계속 게임 진행 //

            printf("\n잘 입력했습니다. 게임이 계속 진행됩니다.\n\n");
            ++turn;
            if (turn > player)
            {
                turn = 1;
            }
        }
    }
}

//멀티플레이 메뉴 //
void MultiPlay()
{
    // 인원 수, 모드 선택 //
    int fd = 0;
    player = 2;
    while (fd == 0)
    {
        SetConsoleTitle(TEXT("369 게임 - 멀티플레이"));
        char fuck[100] = {0};
        system("cls");
        if (player <= 1)
        {
            printf("= ! 경고 ! ================================================");
            printf("\n인원 수는 2명 이상이어야 합니다.");
            printf("\n===========================================================\n");
        }
        printf("===================== 멀티플레이 모드 =====================");
        printf("\n플레이할 인원 수를 입력해 주세요.(최대 8명까지 플레이 가능)");
        printf("\n===========================================================");
        printf("\n입력: "), scanf("%d", &player);
        if (player <= 1)
        {
            continue;
        }
        system("cls");
        if (player > 8)
        {
            printf("= ! 경고 ! ================================================");
            printf("\n9명 이상이서 플레이하고 있습니다. 이는 권장되지 않습니다.");
            printf("\n9명 이상이서 플레이할 경우는 정상 작동을 보장하지 않습니다.");
            printf("\n이 경고는 무시할 수 있습니다.");
            printf("\n===========================================================\n");
        }
        printf("====== 멀티플레이 모드, 플레이어 %d명 ======", player);
        printf("\n=============== 난이도 선택 ===============");
        printf("\n 1 | 일반: 일반적인 369 게임입니다.\n 2 | 어려움: 숫자를 보여주지 않습니다.\n 3 | 인원 수 변경\n 4 | 뒤로 가기");
        printf("\n===========================================");
        printf("\n입력: "), scanf("%d", &mode);
        if (mode == 3)
        {
            continue;
        }
        else if (mode == 4)
        {
            return;
        }
        else if (mode == 1 || mode == 2)
        {
            MultiPlayGame();
            break;
        }
        // 1, 2, 3이 아닌 경우 일반 모드로 진행 //
        else if (mode != 1 && mode != 2)
        {
            printf("1 또는 2가 아닙니다. 일반 모드로 게임을 진행합니다.\n");
            mode = 1;
            system("pause");
            MultiPlayGame();
        }
    }
}

// Main UI //
int main()
{
    SetConsoleTitle(TEXT("369 게임"));
    printf("================================================================================================");
    printf("\n\t                                                                             ");
    printf("\n\t      ######    ####     ####              #####     ##     ##   ##  ######  ");
    printf("\n\t         ##    ##       ##  ##            ##        ####    ### ###  ##      ");
    printf("\n\t        ##     #####     #####            ##       ##  ##   #######  #####   ");
    printf("\n\t         ##    ##  ##       ##            ## ###   ##  ##   ## # ##  ##      ");
    printf("\n\t      ##  ##   ##  ##      ##             ##  ##   ######   ##   ##  ##      ");
    printf("\n\t       ####     ####     ###               #####   ##  ##   ##   ##  ######  ");
    printf("\n\t                                                                             ");
    printf("\n================================================================================================");
    printf("\n\t\t\t\t\t  불러오는 중 ...");
    printf("\n================================================================================================");
    printf("\n\t\t\t\t\t 제작 : pji2918");
    printf("\n\t\t\t  Copyright 2022. pji2918. all rights reserved.");
    printf("\n================================================================================================");
    sleep(5);
    fscanf(fp, "%d", &max);
    int fd = 0;
    srand(time(NULL));
    char q;
    system("cls");
    // 설명 출력 //
    printf("=============== 369 게임 ===============");
    printf("\n369 게임: 돌아가며 3의 배수 여부를 입력하는 게임입니다.");
    printf("\n만약 해당 숫자가 3의 배수이거나, 3이 포함되어 있다면, 1을 입력해야 합니다.");
    printf("\n두 조건을 모두 충족하지 않는 경우 0을 입력하면 됩니다.");
    printf("\n100에 도달할 경우 게임에서 승리하게 됩니다.");
    printf("\n=========================================");
    printf("\n이해했습니까?(y/n) "), scanf(" %c", &q);
    // y / n 입력 및 화면 전환 //
    if (q == 'y')
    {
        while (fd == 0)
        {
            SetConsoleTitle(TEXT("369 게임 - 모드 선택"));
            mode = 0;
            int playmode = 0;
            system("cls");
            printf("=============== 어떻게 플레이하실 건가요? ===============");
            printf("\n 1 | 싱글플레이\n 2 | 멀티플레이 (기록되지 않음)");
            printf("\n 3 | 데이터 삭제\n 4 | 정보\n 5 | 나가기");
            printf("\n=========================================================");
            if (max >= 100)
            {
                printf("\n\t\t    최고 기록: CLEAR");
            }
            else if (max == 0)
            {
                printf("\n\t\t ----- 데이터 없음 -----");
            }
            else
            {
                printf("\n\t\t      최고 기록: %d", max);
            }
            printf("\n=========================================================");
            printf("\n입력: "), scanf("%d", &playmode);
            if (playmode == 4)
            {
                system("cls");
                printf("================================================================================================");
                printf("\n\t                                                                             ");
                printf("\n\t      ######    ####     ####              #####     ##     ##   ##  ######  ");
                printf("\n\t         ##    ##       ##  ##            ##        ####    ### ###  ##      ");
                printf("\n\t        ##     #####     #####            ##       ##  ##   #######  #####   ");
                printf("\n\t         ##    ##  ##       ##            ## ###   ##  ##   ## # ##  ##      ");
                printf("\n\t      ##  ##   ##  ##      ##             ##  ##   ######   ##   ##  ##      ");
                printf("\n\t       ####     ####     ###               #####   ##  ##   ##   ##  ######  ");
                printf("\n\t                                                                             ");
                printf("\n================================================================================================");
                printf("\n\t\t\t\t\t    369 게임");
                printf("\n================================================================================================");
                printf("\n\t\t\t\t\t 제작 : pji2918");
                printf("\n Special Thanks: Stack Overflow, Microsoft, GCC, 어머니, 라이엇 게임즈, My Life is Ruined, GBSW");
                printf("\n\t\t\t  Copyright 2022. pji2918. all rights reserved.");
                printf("\n================================================================================================");
                system("pause>null");
                continue;
            }
            else if (playmode == 5)
            {
                exit(0);
            }
            else if (playmode == 2)
            {
                MultiPlay();
            }
            else if (playmode == 3)
            {
                Remove();
                FILE *fp = fopen("data.sav", "r");
            }
            else if (playmode == 1)
            {
                SinglePlay();
            }
            else
            {
                printf("올바르지 않은 형식입니다.");
            }
        }
    }
    else
    {
        // 히히 잘가 //
        system("cls");
        printf("이해 못했으면 죽어야지.\n");
        system("pause");
        while (1)
        {
            printf("%d", rand());
        }
    }
}