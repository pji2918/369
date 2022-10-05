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

// ���̺� ������ ���� //
void Remove()
{
    SetConsoleTitle(TEXT("369 ���� - ������ ����"));
    char y;
    system("cls");
    printf("������ �����Ͻðڽ��ϱ�?");
    printf("\n�Է�: "), scanf(" %c", &y);
    if (y == 'y')
    {
        system("cls");
        fclose(fp);
        system("del data.sav /q");
        system("cls");
        printf("��� �����͸� �����߽��ϴ�.\n");
        max = 0;
        system("pause");
    }
    else
    {
        system("cls");
    }
}

// �̱��÷��� ���� //
void SinglePlayGame()
{
    system("cls");
    // �ʱ� �� ���� //
    int a = 1;
    int wrong = 0;
    int g = 0;
    int cheat = 0;
    // ���� ���� �� //
    while (1)
    {
        if (mode == 1)
        {
            printf("���� ���ڴ� %d �Դϴ�.", a);
        }
        else
        {
            printf("����� ���� ���ڸ� �������� �ʽ��ϴ�.");
        }
        printf("\n���ڶ�� 0, �ڼ���� 1�� �Է��ϼ���.");
        printf("\n�Է�: "), scanf("%d", &g);
        if (a % 3 == 0 && a != 1)
        {
            // switch������ �Է°� ó�� //
            switch (g)
            {
            case 0:
                // Ʋ�� ��� //
                system("cls");
                printf("Ʋ�Ƚ��ϴ�! %d��/�� 3�� ��������ϴ�.", a);
                wrong = 1;
                break;
            case 1:
                // ���� ��� //
                printf("\n�����Դϴ�!");
                a++;
                break;
            case 780714:
                // ġƮ //
                system("cls");
                printf("ġƮ Ȱ��ȭ! ������ ���� �Է��ϼ���. "), scanf("%d", &a);
                continue;
            default:
                // 0, 1 �Ǵ� ġƮ�� �ƴ� ��� //
                system("cls");
                printf("�ùٸ��� ���� ���Դϴ�.");
                wrong = 1;
                break;
            }
        }
        else if (a % 10 == 3 || a % 30 == 0 || a % 100 / 10 == 3 && a != 1)
        {
            switch (g)
            {
            case 0:
                // Ʋ�� ��� //
                system("cls");
                printf("Ʋ�Ƚ��ϴ�! %d���� 3�� ���ԵǾ� �־����ϴ�.", a);
                wrong = 1;
                break;
            case 1:
                // ���� ��� //
                printf("\n�����Դϴ�!");
                a++;
                break;
            case 780714:
                // ġƮ //
                system("cls");
                printf("ġƮ Ȱ��ȭ! ������ ���� �Է��ϼ���. "), scanf("%d", &a);
                system("cls");
                continue;
                break;
            default:
                // 1, 2, ġƮ�� �ƴ� ��� //
                system("cls");
                printf("�ùٸ��� ���� ���Դϴ�.");
                wrong = 1;
                break;
            }
        }
        else
        {
            // �� �ڵ�� ���� //
            switch (g)
            {
            case 0:
                printf("\n�����Դϴ�!");
                a++;
                break;

            case 1:
                system("cls");
                printf("Ʋ�Ƚ��ϴ�! %d��/�� 3�� ����� �ƴϾ����ϴ�.", a);
                wrong = 1;
                break;
            case 780714:
                system("cls");
                printf("ġƮ Ȱ��ȭ! ������ ���� �Է��ϼ���. "), scanf("%d", &a);
                system("cls");
                continue;
            default:
                system("cls");
                printf("�ùٸ��� ���� ���Դϴ�.");
                wrong = 1;
                break;
            }
        }
        if (wrong == 1)
        {
            char retry = 'n';
            // �й� //
            printf("\n���ӿ��� �й��߽��ϴ�.");
            if (a > max)
            {
                // �ְ� ��� �޼� �� ������ ��� //
                FILE *fp = fopen("data.sav", "w");
                fprintf(fp, "%d", a);
                max = a;
                printf("\n�ְ� ����� �������ϴ�!\n����� �����߽��ϴ�.");
                fclose(fp);
            }
            a = 1;
            wrong = 0;
            g = 0;
            cheat = 0;
            printf("\n�ٽ� �÷����Ͻðڽ��ϱ�?");
            printf("\n�Է�: "), scanf(" %c", &retry);
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
                // ���� �¸� �� �޽��� ��� �� ������ ��� //
                system("cls");
                FILE *fp = fopen("data.sav", "w");
                fprintf(fp, "100");
                printf("�����մϴ�. 100�� �޼��Ͽ� ���ӿ��� �¸��߽��ϴ�.");
                printf("\n�������� ���ϵ帳�ϴ�.");
                printf("\nŬ���� ����� �����߽��ϴ�.");
                printf("\n����: pji2918\n");
                system("pause");
                break;
            }

            // ��� ���� ���� //

            printf("\n�� �Է��߽��ϴ�. ������ ��� ����˴ϴ�.\n\n");
        }
    }
}

// �̱��÷��� �޴� //
void SinglePlay()
{
    // ��� ���� //
    int f = 0;
    while (f == 0)
    {
        SetConsoleTitle(TEXT("369 ���� - �̱��÷���"));
        mode = 0;
        char fuck[100] = {0};
        system("cls");
        printf("============ �̱��÷��� ��� ============");
        printf("\n============== ���̵� ���� ==============");
        printf("\n 1 | �Ϲ�: �Ϲ����� 369 �����Դϴ�.\n 2 | �����: ���ڸ� �������� �ʽ��ϴ�.\n 3 | �ڷ� ����");
        printf("\n=========================================");
        if (max >= 100)
        {
            printf("\n\t    �ְ� ���: CLEAR");
        }
        else if (max == 0)
        {
            printf("\n\t ----- ������ ���� -----");
        }
        else
        {
            printf("\n\t      �ְ� ���: %d", max);
        }
        printf("\n=========================================");
        printf("\n�Է�: "), scanf("%d", &mode);
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
        // 1, 2, 3�� �ƴ� ��� �Ϲ� ���� ���� //
        else if (mode != 1 && mode != 2 && mode != 18)
        {
            printf("1 �Ǵ� 2�� �ƴմϴ�. �Ϲ� ���� ������ �����մϴ�.\n");
            mode = 1;
            system("pause");
            SinglePlayGame();
        }
    }
}

// ��Ƽ�÷��� ���� //
void MultiPlayGame()
{
    system("cls");
    // �ʱ� �� ���� //
    int a = 1;
    int wrong = 0;
    int g = 0;
    int cheat = 0;
    int count = 0;
    int turn = 1;
    int die[player + 1] = {0};
    // ���� ���� �� //
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
            printf("%d��° �÷��̾ �¸��߽��ϴ�!", turn);
            printf("\n������ ���ڴ� %d�����ϴ�.", a);
            printf("\n�÷������ּż� �����մϴ�!");
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
            printf("%d��° �÷��̾ 100�� �޼��Ͽ� �¸��߽��ϴ�!", turn);
            printf("\n�÷������ּż� �����մϴ�!");
            system("pause");
            break;
        }
        printf("%d��° �÷��̾��� �����Դϴ�.", turn);
        if (mode == 1)
        {
            printf("\n���� ���ڴ� %d �Դϴ�.", a);
        }
        else
        {
            printf("\n����� ���� ���ڸ� �������� �ʽ��ϴ�.");
        }
        printf("\n���ڶ�� 0, �ڼ���� 1�� �Է��ϼ���.");
        printf("\n�Է�: "), scanf("%d", &g);
        if (a % 3 == 0 && a != 1)
        {
            // switch������ �Է°� ó�� //
            switch (g)
            {
            case 0:
                // Ʋ�� ��� //
                system("cls");
                printf("Ʋ�Ƚ��ϴ�! %d��/�� 3�� ��������ϴ�.", a);
                wrong = 1;
                break;
            case 1:
                // ���� ��� //
                printf("\n�����Դϴ�!");
                a++;
                break;
            case 780714:
                // ġƮ //
                system("cls");
                printf("ġƮ Ȱ��ȭ! ������ ���� �Է��ϼ���. "), scanf("%d", &a);
                continue;
            default:
                // 0, 1 �Ǵ� ġƮ�� �ƴ� ��� //
                system("cls");
                printf("�ùٸ��� ���� ���Դϴ�.");
                wrong = 1;
                break;
            }
        }
        else if (a % 10 == 3 || a % 30 == 0 || a % 100 / 10 == 3 && a != 1)
        {
            switch (g)
            {
            case 0:
                // Ʋ�� ��� //
                system("cls");
                printf("Ʋ�Ƚ��ϴ�! %d���� 3�� ���ԵǾ� �־����ϴ�.", a);
                wrong = 1;
                break;
            case 1:
                // ���� ��� //
                printf("\n�����Դϴ�!");
                a++;
                break;
            case 780714:
                // ġƮ //
                system("cls");
                printf("ġƮ Ȱ��ȭ! ������ ���� �Է��ϼ���. "), scanf("%d", &a);
                system("cls");
                continue;
                break;
            default:
                // 1, 2, ġƮ�� �ƴ� ��� //
                system("cls");
                printf("�ùٸ��� ���� ���Դϴ�.");
                wrong = 1;
                break;
            }
        }
        else
        {
            // �� �ڵ�� ���� //
            switch (g)
            {
            case 0:
                printf("\n�����Դϴ�!");
                a++;
                break;

            case 1:
                system("cls");
                printf("Ʋ�Ƚ��ϴ�! %d��/�� 3�� ����� �ƴϾ����ϴ�.", a);
                wrong = 1;
                break;
            case 780714:
                system("cls");
                printf("ġƮ Ȱ��ȭ! ������ ���� �Է��ϼ���. "), scanf("%d", &a);
                system("cls");
                continue;
            default:
                system("cls");
                printf("�ùٸ��� ���� ���Դϴ�.");
                wrong = 1;
                break;
            }
        }
        if (wrong == 1)
        {
            // �й� //
            printf("\n%d��° �÷��̾ Ż���߽��ϴ�.\n", turn);
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

            // ��� ���� ���� //

            printf("\n�� �Է��߽��ϴ�. ������ ��� ����˴ϴ�.\n\n");
            ++turn;
            if (turn > player)
            {
                turn = 1;
            }
        }
    }
}

//��Ƽ�÷��� �޴� //
void MultiPlay()
{
    // �ο� ��, ��� ���� //
    int fd = 0;
    player = 2;
    while (fd == 0)
    {
        SetConsoleTitle(TEXT("369 ���� - ��Ƽ�÷���"));
        char fuck[100] = {0};
        system("cls");
        if (player <= 1)
        {
            printf("= ! ��� ! ================================================");
            printf("\n�ο� ���� 2�� �̻��̾�� �մϴ�.");
            printf("\n===========================================================\n");
        }
        printf("===================== ��Ƽ�÷��� ��� =====================");
        printf("\n�÷����� �ο� ���� �Է��� �ּ���.(�ִ� 8����� �÷��� ����)");
        printf("\n===========================================================");
        printf("\n�Է�: "), scanf("%d", &player);
        if (player <= 1)
        {
            continue;
        }
        system("cls");
        if (player > 8)
        {
            printf("= ! ��� ! ================================================");
            printf("\n9�� �̻��̼� �÷����ϰ� �ֽ��ϴ�. �̴� ������� �ʽ��ϴ�.");
            printf("\n9�� �̻��̼� �÷����� ���� ���� �۵��� �������� �ʽ��ϴ�.");
            printf("\n�� ���� ������ �� �ֽ��ϴ�.");
            printf("\n===========================================================\n");
        }
        printf("====== ��Ƽ�÷��� ���, �÷��̾� %d�� ======", player);
        printf("\n=============== ���̵� ���� ===============");
        printf("\n 1 | �Ϲ�: �Ϲ����� 369 �����Դϴ�.\n 2 | �����: ���ڸ� �������� �ʽ��ϴ�.\n 3 | �ο� �� ����\n 4 | �ڷ� ����");
        printf("\n===========================================");
        printf("\n�Է�: "), scanf("%d", &mode);
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
        // 1, 2, 3�� �ƴ� ��� �Ϲ� ���� ���� //
        else if (mode != 1 && mode != 2)
        {
            printf("1 �Ǵ� 2�� �ƴմϴ�. �Ϲ� ���� ������ �����մϴ�.\n");
            mode = 1;
            system("pause");
            MultiPlayGame();
        }
    }
}

// Main UI //
int main()
{
    SetConsoleTitle(TEXT("369 ����"));
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
    printf("\n\t\t\t\t\t  �ҷ����� �� ...");
    printf("\n================================================================================================");
    printf("\n\t\t\t\t\t ���� : pji2918");
    printf("\n\t\t\t  Copyright 2022. pji2918. all rights reserved.");
    printf("\n================================================================================================");
    sleep(5);
    fscanf(fp, "%d", &max);
    int fd = 0;
    srand(time(NULL));
    char q;
    system("cls");
    // ���� ��� //
    printf("=============== 369 ���� ===============");
    printf("\n369 ����: ���ư��� 3�� ��� ���θ� �Է��ϴ� �����Դϴ�.");
    printf("\n���� �ش� ���ڰ� 3�� ����̰ų�, 3�� ���ԵǾ� �ִٸ�, 1�� �Է��ؾ� �մϴ�.");
    printf("\n�� ������ ��� �������� �ʴ� ��� 0�� �Է��ϸ� �˴ϴ�.");
    printf("\n100�� ������ ��� ���ӿ��� �¸��ϰ� �˴ϴ�.");
    printf("\n=========================================");
    printf("\n�����߽��ϱ�?(y/n) "), scanf(" %c", &q);
    // y / n �Է� �� ȭ�� ��ȯ //
    if (q == 'y')
    {
        while (fd == 0)
        {
            SetConsoleTitle(TEXT("369 ���� - ��� ����"));
            mode = 0;
            int playmode = 0;
            system("cls");
            printf("=============== ��� �÷����Ͻ� �ǰ���? ===============");
            printf("\n 1 | �̱��÷���\n 2 | ��Ƽ�÷��� (��ϵ��� ����)");
            printf("\n 3 | ������ ����\n 4 | ����\n 5 | ������");
            printf("\n=========================================================");
            if (max >= 100)
            {
                printf("\n\t\t    �ְ� ���: CLEAR");
            }
            else if (max == 0)
            {
                printf("\n\t\t ----- ������ ���� -----");
            }
            else
            {
                printf("\n\t\t      �ְ� ���: %d", max);
            }
            printf("\n=========================================================");
            printf("\n�Է�: "), scanf("%d", &playmode);
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
                printf("\n\t\t\t\t\t    369 ����");
                printf("\n================================================================================================");
                printf("\n\t\t\t\t\t ���� : pji2918");
                printf("\n Special Thanks: Stack Overflow, Microsoft, GCC, ��Ӵ�, ���̾� ������, My Life is Ruined, GBSW");
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
                printf("�ùٸ��� ���� �����Դϴ�.");
            }
        }
    }
    else
    {
        // ���� �߰� //
        system("cls");
        printf("���� �������� �׾����.\n");
        system("pause");
        while (1)
        {
            printf("%d", rand());
        }
    }
}