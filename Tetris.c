// coding = UTF-8
// 俄罗斯方块写于2017年6月
// c语言程序设计

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

#define FALSE 0
#define TRUE  1

//全局变量
HANDLE L_Handle;   //窗口句柄
COORD L_WeiZhi;    //设置位置结构体
int Star = 1;      //游戏运行
int L_LEVEL = 1;   //等级
float L_SuDu = 0.45;
int L_SCORE = 0;  //分数
int L_a = -1;     //方块位置a
int L_b = 4;      //方块位置b
int L_FangKuaiDaoDi = 1;

typedef struct
{
    char name[10];
    int score;
}Plear;

int L_KuangJia[21][14] =    //设置刷屏数组
{
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

int L_Fangkuai[4][4];
int a[4][4] =
{
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {1,1,1,1},
};
int a1[4][4] =
{
    {1,0,0,0},
    {1,0,0,0},
    {1,0,0,0},
    {1,0,0,0},
};      //变形版本

int b[4][4] =
{
    {0,0,0,0},
    {0,0,0,0},
    {1,1,0,0},
    {1,1,0,0},
};
int c[4][4] =
{
    {0,0,0,0},
    {1,1,0,0},
    {1,0,0,0},
    {1,0,0,0},
};
int c1[4][4] =
{
    {0,0,0,0},
    {0,0,0,0},
    {1,1,1,0},
    {0,0,1,0},
};
int c2[4][4] =
{
    {0,0,0,0},
    {0,1,0,0},
    {0,1,0,0},
    {1,1,0,0},
};
int c3[4][4] =
{
    {0,0,0,0},
    {0,0,0,0},
    {1,0,0,0},
    {1,1,1,0},
};

int d[4][4] =
{
    {0,0,0,0},
    {0,0,0,0},
    {0,1,0,0},
    {1,1,1,0},
};
int d1[4][4] =
{
    {0,0,0,0},
    {1,0,0,0},
    {1,1,0,0},
    {1,0,0,0},
};
int d2[4][4] =
{
    {0,0,0,0},
    {0,0,0,0},
    {1,1,1,0},
    {0,1,0,0},
};
int d3[4][4] =
{
    {0,0,0,0},
    {0,1,0,0},
    {1,1,0,0},
    {0,1,0,0},
};

int e[4][4] =
{
    {0,0,0,0},
    {1,1,0,0},
    {0,1,0,0},
    {0,1,0,0},
};
int e1[4][4] =
{
    {0,0,0,0},
    {0,0,0,0},
    {0,0,1,0},
    {1,1,1,0},
};
int e2[4][4] =
{
    {0,0,0,0},
    {1,0,0,0},
    {1,0,0,0},
    {1,1,0,0},
};
int e3[4][4] =
{
    {0,0,0,0},
    {0,0,0,0},
    {1,1,1,0},
    {1,0,0,0},
};


int f[4][4] =
{
    {0,0,0,0},
    {0,0,0,0},
    {1,1,0,0},
    {0,1,1,0},
};
int f1[4][4] =
{
    {0,0,0,0},
    {0,1,0,0},
    {1,1,0,0},
    {1,0,0,0},
};

int g[4][4] =
{
    {0,0,0,0},
    {0,0,0,0},
    {0,1,1,0},
    {1,1,0,0},
};
int g1[4][4] =
{
    {0,0,0,0},
    {1,0,0,0},
    {1,1,0,0},
    {0,1,0,0},
};

void YingXiongBang(void);
int H_GameXuanXiang(void);      //游戏选项--3个 开始游戏 英雄榜 退出
void H_SetAdd(int x, int y);    //设置光标位置
void H_PrintGame(void);         //打印游戏界面  用来刷新帧数
void H_PrintKuangJia(void);     //打印框架  --包括 等级 操作提示
void GAME(void);                //游戏界面
void H_InsertFangkuai(void);    //插入游戏方块
void H_MoveDown(void);          //方块向下移动
int H_MoveDownText(void);       //向下移动测试
void H_MoveLeft(void);          //方块向左移动
int H_MoveLeftText(void);       //向左移动测试
void H_MoveRight(void);          //方块向右移动
int H_MoveRightText(void);       //向右移动测试
void H_KeyChose(void);
void H_BianXing(void);          //变形函数
int H_PD(int SZ[4][4]);         //判断与随机方块是否相等
void H_FuZhi(int FK[4][4]);     //把模型复制到随机方块里边
void H_XiaoQu(void);            //消去函数
void H_ScoreLevel(void);
int H_OVER(void);               //判断结束
void H_BaoCun(Plear);
void sort(Plear *);

int main()
{
    int chose;
    Plear name;
    L_Handle = GetStdHandle(STD_OUTPUT_HANDLE); //获得句柄
    system("title 俄罗斯方块");  //设置标题：俄罗斯方块
    srand((unsigned)time(0));   //重置随机数种子

    chose = H_GameXuanXiang();
    if (chose == 1)
    {
        GAME();
        system("cls");
        H_SetAdd(20, 5);
        printf("你的得分为：%d\n", L_SCORE);
        H_SetAdd(20, 6);
        printf("请输入你的名字：");
        gets(name.name);
        name.score = L_SCORE;
        H_BaoCun(name);
    }
    else if (chose == 2)
    {
        YingXiongBang();
    }

    return 0;
}

//游戏界面
void GAME(void)
{
    system("cls");
    H_PrintKuangJia();

    while (Star)    //开始游戏
    {
        H_InsertFangkuai();
        H_KeyChose();
        if (H_OVER())
        {
            return;
        }
    }
}


//设置光标位置
void H_SetAdd(int x, int y)
{
    L_WeiZhi.X = x;
    L_WeiZhi.Y = y;
    SetConsoleCursorPosition(L_Handle, L_WeiZhi);
}

//开始界面

int H_GameXuanXiang(void)
{
    int chose = 1;
    char getkey;

    H_SetAdd(28,6);
    printf("==Program Project Tetris==");

    while (chose != 0)
    {
        if (chose == 1)
        {
            H_SetAdd(36, 8);
            SetConsoleTextAttribute(L_Handle, 0xf0);
            printf("1. 开始");
            H_SetAdd(36, 9);
            SetConsoleTextAttribute(L_Handle, 0x07);
            printf("2. 英雄榜\n");
            H_SetAdd(36, 10);
            printf("3. 退出\n");
        }
        else if (chose == 2)
        {
            H_SetAdd(36, 8);
            printf("1. 开始");
            H_SetAdd(36, 9);
            SetConsoleTextAttribute(L_Handle, 0xf0);
            printf("2. 英雄榜\n");
            SetConsoleTextAttribute(L_Handle, 0x07);
            H_SetAdd(36, 10);
            printf("3. 退出\n");
        }
        else if (chose == 3)
        {
            H_SetAdd(36, 8);
            printf("1. 开始");
            H_SetAdd(36, 9);
            printf("2. 英雄榜\n");
            H_SetAdd(36, 10);
            SetConsoleTextAttribute(L_Handle, 0xf0);
            printf("3. 退出\n");
            SetConsoleTextAttribute(L_Handle, 0x07);
        }

        getkey  = getch();
        if (getkey == 72 || getkey == 'w' || getkey == 'W')
        {
            if (chose > 1)
            {
                chose--;
            }

        }
        else if (getkey == 80 || getkey == 's' || getkey == 'S')
        {
            if (chose < 3)
            {
                chose++;
            }
        }
        else if (getkey == '\r' || getkey == 10)
        {
            break;
        }
    }

    return chose;
}

//打印框架
void H_PrintKuangJia(void)
{
    int i;

    SetConsoleTextAttribute(L_Handle, 0xf0);

    for (i = 0; i < 20; i++)
    {
        H_SetAdd(18, i);
        printf("%-2s", " ");
    }
    for (i = 0; i < 20; i++)
    {
        H_SetAdd(44, i);
        printf("%-2s", " ");
    }

    H_SetAdd(18, 20);
    for (i = 18; i < 32; i++)
    {
        printf("%-2s", " ");
    }

    SetConsoleTextAttribute(L_Handle, 0xf0);
    for (i = 0; i < 5; i++)
    {
        H_SetAdd(54,2+i);
        printf("┃");
        H_SetAdd(64,2+i);
        printf("┃");
    }
    H_SetAdd(54,1);
    printf("┏━━━━┓");
    H_SetAdd(54,7);
    printf("┗━━━━┛");


    SetConsoleTextAttribute(L_Handle, 0x0f);
    H_SetAdd(6,2);
    printf("等级:%d", L_LEVEL);
    H_SetAdd(6,3);
    printf("分数:%d", L_SCORE);
    H_SetAdd(54,8);
    SetConsoleTextAttribute(L_Handle,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    printf("功能      键1     键2");
    SetConsoleTextAttribute(L_Handle,FOREGROUND_RED|FOREGROUND_INTENSITY);
    H_SetAdd(54,10);
    printf("暂停      [P] ");
    H_SetAdd(54,11);
    printf("变形      [W]     [↑] ");
    H_SetAdd(54,12);
    printf("左        [A]     [←] ");
    H_SetAdd(54,13);
    printf("右        [D]     [→] ");
    H_SetAdd(54,14);
    printf("下        [S]     [↓] ");
    H_SetAdd(54,15);
    printf("落        [ ]     [space] ");
}


//打印游戏刷屏界面
void H_PrintGame(void)
{
    int i;
    int j;
    int k = 0;

    SetConsoleTextAttribute(L_Handle, 0x0f);
    for (i = 0; i < 20; i++)
    {
        H_SetAdd(20, k++);
        for (j = 1; j < 13; j++)
        {
            if (L_KuangJia[i][j] == 1)
            {
                printf("■");
            }
            else
            {
                printf("  ");
            }
        }
    }
    H_SetAdd(0,21);
}

void H_KeyChose()
{
    char a;
    char b;
    int PAUSE = 0;
    int m = 0;
    int i, j;
    clock_t clockNow, clockLast;

    clockLast = clock();

    while(!L_FangKuaiDaoDi)
    {
      if(PAUSE==0)
        {
            if(kbhit())
            {
                a=getch();
                if(a=='a'||a=='A'||a==75)
                        H_MoveLeft();
                else if(a=='d'||a=='D'||a==77)
                        H_MoveRight();
                else if(a=='s'||a=='S'||a==80)
                        H_MoveDown();
                else if(a=='w'||a=='W'||a==72)
                        H_BianXing();
                else if(a=='p'||a=='P')
                {
                    PAUSE=1;
                    H_SetAdd(25,7);
                    printf("游戏暂停!");
                    H_SetAdd(25,8);
                    printf("键入P键恢复");
                    H_SetAdd(25,9);
                }
            }
            clockNow = clock();

            if (clockNow - clockLast > L_SuDu * CLOCKS_PER_SEC)//if twice time max 0.45s ,down;
            {
                clockLast = clockNow;
                H_MoveDown();
            }
        }
        else if(kbhit())
        {
            b = getch();
            if (b == 'P' || b == 'p')
            {
                PAUSE = 0;
            }

        }
    }
}


//随机插入一个方块

void H_InsertFangkuai(void)
{
    int suiJiFangKuai;
    int i;
    int j;

    if (L_FangKuaiDaoDi)
    {
        H_XiaoQu(); //判断消去
        suiJiFangKuai = rand() % 7; //选择随机方块

        //把随机方块放到 方块里边
        if (suiJiFangKuai == 0)
        {
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    L_Fangkuai[i][j] = a[i][j];
                }
            }
        }
        else if(suiJiFangKuai == 1)
        {
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    L_Fangkuai[i][j] = b[i][j];
                }
            }
        }
        else if(suiJiFangKuai == 2)
        {
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    L_Fangkuai[i][j] = c[i][j];
                }
            }
        }
        else if(suiJiFangKuai == 3)
        {
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    L_Fangkuai[i][j] = d[i][j];
                }
            }
        }
        else if(suiJiFangKuai == 4)
        {
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    L_Fangkuai[i][j] = e[i][j];
                }
            }
        }
        else if(suiJiFangKuai == 5)
        {
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    L_Fangkuai[i][j] = f[i][j];
                }
            }
        }
        else if(suiJiFangKuai == 6)
        {
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    L_Fangkuai[i][j] = g[i][j];
                }
            }
        }

        L_a = -1;
        L_b = 5;
        L_FangKuaiDaoDi = 0;  //重置为未到底
    }
}

//向下移动测试
int H_MoveDownText(void)
{
    int i;  //行
    int j;  //列
    int flag = 0;

    //如何测试--从下边测试仅仅测试一个方格
    for (j = 0; j < 4; j++)
    {
        for (i = 3; i >= 0; i--)
        {
            if (L_Fangkuai[i][j] == 1)
            {
                if (L_KuangJia[L_a-2+i][L_b+j] == 1)
                {
                    flag = 1;
                    goto there;
                }
                break;
            }
        }
    }

there:
    if (flag == 1)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

//向下移动
void H_MoveDown(void)
{
    //2.向下移动
    int i;
    int j;
    int k;
    int l;

    if (H_MoveDownText())     //成功，则刷新一下帧数
    {
        L_a++;     //使指向下一个位置
        //清理上一个位置
        for (i = 0, k = L_a - 4; i < 4; i++, k++)
        {
            for (j = 0, l = L_b; j < 4; j++, l++)
            {
                if (k >= 0 && L_Fangkuai[i][j] == 1)
                {
                    L_KuangJia[k][l] = 0;
                }
            }
        }
        //更新图像到这个位置
        for (i = 0, k = L_a - 3; i < 4; i++, k++)
        {
            for (j = 0, l = L_b; j < 4; j++, l++)
            {
                if (k >= 0 && L_Fangkuai[i][j] == 1)
                {
                    L_KuangJia[k][l] = L_Fangkuai[i][j];
                }
            }
        }
    }
    else
    {
        L_FangKuaiDaoDi = 1;    //提示方块到底
    }
    H_PrintGame();
}

//左移测试
int H_MoveLeftText(void)
{
    int i;  //行
    int j;  //列

    int flag = 0;

    //如何测试--从左边测试仅仅测试一个方格

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (L_Fangkuai[i][j] == 1)
            {
                if (L_KuangJia[L_a-3+i][L_b+j-1] == 1)
                {
                    flag = 1;
                    goto there;
                }
                break;
            }
        }
    }

there:
    if (flag == 1)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

//左移动
void H_MoveLeft(void)
{
    int i;
    int j;
    int k;
    int l;

    if (H_MoveLeftText())     //成功，则刷新一下帧数
    {
        L_b--;      //使指向下一个位置
        //清理上一个位置
        for (i = 0, k = L_a - 3; i < 4; i++, k++)
        {
            for (j = 0, l = L_b + 1; j < 4; j++, l++)
            {
                if (k >= 0 && L_Fangkuai[i][j] == 1)
                {
                    L_KuangJia[k][l] = 0;
                }
            }
        }
        //更新图像到这个位置
        for (i = 0, k = L_a - 3; i < 4; i++, k++)
        {
            for (j = 0, l = L_b; j < 4; j++, l++)
            {
                if (k >= 0 && L_Fangkuai[i][j] == 1)
                {
                    L_KuangJia[k][l] = L_Fangkuai[i][j];
                }
            }
        }
    }
    H_PrintGame();
}

//右移测试
int H_MoveRightText(void)
{
    int i;
    int j;
    int flag = 0;

    //从右边测试
    for (i = 0; i < 4; i++)
    {
        for (j = 3; j >= 0; j--)
        {
            if (L_Fangkuai[i][j] == 1)
            {
                if (L_KuangJia[L_a-3+i][L_b+1+j] == 1)
                {
                    flag = 1;
                    goto there;
                }
                break;
            }
        }
    }

there:
    if (flag == 1)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

//右移动
void H_MoveRight(void)
{
    int i;
    int j;
    int k;
    int l;

    if (H_MoveRightText())     //成功，则刷新一下帧数
    {
        L_b++;      //使指向下一个位置
        //清理上一个位置
        for (i = 0, k = L_a - 3; i < 4; i++, k++)
        {
            for (j = 0, l = L_b - 1; j < 4; j++, l++)
            {
                if (k >= 0 && L_Fangkuai[i][j] == 1)
                {
                    L_KuangJia[k][l] = 0;
                }
            }
        }
        //更新图像到这个位置
        for (i = 0, k = L_a - 3; i < 4; i++, k++)
        {
            for (j = 0, l = L_b; j < 4; j++, l++)
            {
                if (k >= 0 && L_Fangkuai[i][j] == 1)
                {
                    L_KuangJia[k][l] = L_Fangkuai[i][j];
                }
            }
        }
    }
    H_PrintGame();
}

int H_PD(int SZ[4][4])
{
    int i;
    int j;
    int flag = 1;   //相等

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (L_Fangkuai[i][j] != SZ[i][j])
            {
                flag = 0;   //不相等
                return flag;
            }
        }
    }

    return flag;
}

void H_FuZhi(int FK[4][4])
{
    int i;
    int j;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            L_Fangkuai[i][j] = FK[i][j];
        }
    }
}

void H_BianXing(void)
{
    int i;
    int j;
    int yuan[4][4];

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            yuan[i][j] = L_Fangkuai[i][j];
        }
    }

    if (H_PD(a))
    {
        H_FuZhi(a1);
    }
    else if(H_PD(a1))
    {
        H_FuZhi(a);
    }
    else if(H_PD(c))
    {
        H_FuZhi(c1);
    }
    else if(H_PD(c1))
    {
        H_FuZhi(c2);
    }
    else if(H_PD(c2))
    {
        H_FuZhi(c3);
    }
    else if(H_PD(c3))
    {
        H_FuZhi(c);
    }
    else if(H_PD(d))
    {
        H_FuZhi(d1);
    }
    else if(H_PD(d1))
    {
        H_FuZhi(d2);
    }
    else if(H_PD(d2))
    {
        H_FuZhi(d3);
    }
    else if(H_PD(d3))
    {
        H_FuZhi(d);
    }
    else if(H_PD(e))
    {
        H_FuZhi(e1);
    }
    else if(H_PD(e1))
    {
        H_FuZhi(e2);
    }
    else if(H_PD(e2))
    {
        H_FuZhi(e3);
    }
    else if(H_PD(e3))
    {
        H_FuZhi(e);
    }
    else if(H_PD(f))
    {
        H_FuZhi(f1);
    }
    else if(H_PD(f1))
    {
        H_FuZhi(f);
    }
    else if(H_PD(g))
    {
        H_FuZhi(g1);
    }
    else if(H_PD(g1))
    {
        H_FuZhi(g);
    }
    else
    {
        return;
    }

    //清理
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (yuan[i][j] == 1)
            {
                L_KuangJia[L_a-3+i][L_b+j] = 0;
            }
        }
    }

    //更新
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (L_Fangkuai[i][j] == 1)
            {
                L_KuangJia[L_a-3+i][L_b+j] = 1;
            }
        }
    }
    H_PrintGame();
}

//分数如何计算？
//每消去一行 1*等级
//等级 每30分一个等级

void H_ScoreLevel(void)
{
    if (L_SCORE > 150)
    {
        L_LEVEL = 6;
        L_SuDu = 0.10;
    }
    else if (L_SCORE > 120)
    {
        L_LEVEL = 5;
        L_SuDu = 0.20;
    }
    else if (L_SCORE > 90)
    {
        L_LEVEL = 4;
        L_SuDu = 0.30;
    }
    else if (L_SCORE > 60)
    {
        L_LEVEL = 3;
        L_SuDu = 0.35;
    }
    else if (L_SCORE > 30)
    {
        L_LEVEL = 2;
        L_SuDu = 0.40;
    }
}

void H_XiaoQu(void)
{
    //如何消去呢？
    //如果到底了，就判断一下 前边的四行 有没有全部为1的。
    //如果全部为1，就消去，也就是除去这一行，的上边的全部，复制到下边。
    //把这个函数，放到 产生新方块之前，因为每到底一次

    int i;
    int j;
    int ii;
    int jj;
    int flag = 1;   //能够下移

    for (i = 3; i >= 0; i--)
    {
        for (j = 1; j < 13; j++)
        {
            if (L_KuangJia[L_a-i][j] != 1)
            {
                //存在不等于1
                flag = 0;
                break;
            }
        }
        if (flag)   //能够下移
        {
            L_SCORE+=L_LEVEL;        //增加分数
            H_ScoreLevel();                     //判断等级
            H_SetAdd(6,2);
            printf("等级:%d", L_LEVEL);
            H_SetAdd(6,3);
            printf("分数:%d", L_SCORE);

            for (ii = L_a; ii > 0; ii--)
            {
                for (jj = 1; jj < 13; jj++)
                {
                    L_KuangJia[ii][jj] = L_KuangJia[ii-1][jj];
                }
            }
            i++;
        }
        flag = 1;
    }
}

int H_OVER(void)
{
    //如何判断结束
    if (L_KuangJia[0][5] ||
        L_KuangJia[0][6] ||
        L_KuangJia[0][7] ||
        L_KuangJia[0][8])
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void H_BaoCun(Plear plear)
{
    FILE *fp;
    Plear data[11];

    if ((fp = fopen("data.dat", "rb+")) == NULL)
    {
        exit(0);
    }
    fread(data, sizeof(Plear), 10, fp);
    fclose(fp);
    fp = NULL;
    data[10] = plear;
    sort(data);

    if ((fp = fopen("data.dat", "wb+")) == NULL)
    {
        printf("数据保存失败！");
    }

    fwrite(&data, sizeof(Plear), 10, fp);
    fclose(fp);
}

void YingXiongBang(void)
{
    int i = 0;
    Plear plear[10];
    FILE *fp;

    if ((fp = fopen("data.dat", "rb+")) == NULL)
    {
        exit(0);
    }

    fread(plear, sizeof(Plear), 10, fp);
    system("cls");
    printf("\t\t\tTop10 list\n");
    printf("------------------------------------------------------------------\n");
    printf("\t rank\t\tscore\t\tplayer\n");
    printf("------------------------------------------------------------------\n");
    while (i < 10)
    {
        printf("\t %d\t\t %d\t\t %s\n", i+1, plear[i].score, plear[i].name);
        i++;
    }

    fclose(fp);
    printf("------------------------------------------------------------------\n");
}

void sort(Plear plear[11])
{
    int i;
    int j;
    Plear temp;

    for (j = 0; j < 10; j++)
        for (i = 0; i < 10-j; i++)
        {
            if (plear[i].score > plear[i+1].score)
            {
                temp = plear[i];
                plear[i] =plear[i+1];
                plear[i+1] = temp;
            }
        }
}


