#include <iostream>
#include <fstream>
#include <iomanip>
#include "raylib.h"
using namespace std;
const int swidth = 800, sheight = 800;
int row= 2, col=2, choice, choice2;
bool another_first = true;

void visual_file_read()
{
    cout<<"visual file read"<<endl;
}

void visual_random()
{
    static bool isfirsttime = true;
    cout<<"visual random"<<endl;
    ClearBackground(BLUE);
    if(isfirsttime)
    {
        DrawText("Choose difficulty", 100, 200, 60, BLACK);

        DrawRectangle(250, 300,300,100, GRAY );
        DrawRectangleLines(250, 300,300,100, BLACK);
        DrawText("Easy", 300,340, 30, BLACK);
        
        DrawRectangle(250, 420,300,100, GRAY );
        DrawRectangleLines(250, 420,300,100, BLACK);
        DrawText("medium", 300,460, 30, BLACK);

        DrawRectangle(250, 540,300,100, GRAY );
        DrawRectangleLines(250, 540,300,100, BLACK);
        DrawText("Hard", 300,580, 30, BLACK);
        
        DrawRectangle(250, 660,300,100, GRAY );
        DrawRectangleLines(250, 660,300,100, BLACK);
        DrawText("Insane", 300,700, 30, BLACK);
        Vector2 mousepos = {-100.0f, -100.0f};
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            mousepos = GetMousePosition();
            if(mousepos.x >=250 && mousepos.x <=550 && mousepos.y >= 300 && mousepos.y < 400)
            {
                cout<<"Easy difficulty"<<endl;
                row = 5, col =5;
                isfirsttime = false;
                choice2 = 1;
                another_first = false;
            }

            else if(mousepos.x >=250 && mousepos.x <=550 && mousepos.y >= 420 && mousepos.y < 520)
            {
                cout<<"Medium Difficulty"<<endl;
                row = 6, col =6;
                isfirsttime = false;
                choice2 = 2;
                another_first = false;
            }

            else if(mousepos.x >=250 && mousepos.x <=550 && mousepos.y >= 540 && mousepos.y < 640)
            {
                cout<<"Hard Difficulty"<<endl;
                row = 7, col =7;
                isfirsttime = false;
                choice2 = 3;
                another_first = false;
            }

            else if(mousepos.x >=250 && mousepos.x <=550 && mousepos.y >= 660 && mousepos.y < 760)
            {
                cout<<"Insane Difficulty"<<endl;
                row = 9, col =9;
                isfirsttime = false;
                choice2 = 4;
                another_first = false;
            } 
        }   
    }
}

void main_menu(const int& swidth, const int& sheight)
{
    static bool first_time2 = true, visRand = false, visfile = false;
    ClearBackground(BLUE);
    if(first_time2)
    {

        DrawText("Welcome to the game", 100, 300, 60, BLACK);

        DrawRectangle(250, 400,300,100, GRAY );
        DrawRectangleLines(250, 400,300,100, BLACK);
        DrawText("file reading", 300,440, 30, BLACK);
        
        DrawRectangle(250, 520,300,100, GRAY );
        DrawRectangleLines(250, 520,300,100, BLACK);
        DrawText("random", 300,560, 30, BLACK);

        Vector2 mousepos = {-100.0f, -100.0f};

        // mousepos = GetMousePosition();
        // DrawText(TextFormat("pos x: %f pos y: %f", mousepos.x, mousepos.y), 0,0, 30, BLACK);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            mousepos = GetMousePosition();
            if(mousepos.x >=250 && mousepos.x <=550 && mousepos.y >= 400 && mousepos.y < 500)
            {
                cout<<"visual file read"<<endl;
                visfile = true;
                choice = 1;
                // visual_file_read();
            }

            else if(mousepos.x >=250 && mousepos.x <=550 && mousepos.y >= 520 && mousepos.y < 620)
            {
                cout<<"visual random"<<endl;
                visRand = true;
                choice = 2;
            }    
            first_time2 = false;

        }
    }
    else if(visRand)
        visual_random();
    
    else if(visfile)
        visual_file_read();
}

void print_over_screen()
{
    ClearBackground(BLUE);
    DrawText("Game over!!", 200, 300,80,BLACK);
    DrawText("Better luck next time", 100, 400,60,GOLD);

}

void won_screen()
{
    ClearBackground(BLUE);
    DrawText("You won!!", 200, 300,80,BLACK);
}

void print_grid_raylib(int** grid,bool** isopen, int row, int col)
{
    int ind_x = 800/col, ind_y = 800/row;
    for(int i =0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(isopen[i][j])
            {
                DrawRectangle(ind_x*j, ind_y * i, ind_x, ind_y, WHITE);
                DrawText(TextFormat("%i",grid[i][j]), ((ind_x*j) + (ind_x*(j+1)))/2, ((ind_y*i) + (ind_y*(i+1)))/2,25,BLUE);
            }
                
            else
                DrawRectangle(ind_x*j, ind_y * i, ind_x, ind_y, GRAY);
            
            DrawRectangleLines(ind_x*j, ind_y * i, ind_x, ind_y, BLACK);
        }
    }
}

void print_grid(int** grid,bool** isopen, int row, int col)
{
    for(int i=0; i<row; i++)
    {
        for(int k =0; k<row; k++)
        {
            cout<<"----";
        }
        cout<<endl<<"|";
        for(int j=0; j<col; j++)
        {
           if(isopen[i][j])
                cout<<setw(2)<<grid[i][j]<<" |";
            else
                cout<<setw(2)<<"x"<<" |";
        }
        cout<<endl;
    }
    for(int k =0; k<row; k++)
        {
            cout<<"----";
        }
    cout<<endl;
}

void print_grid(int** grid, int row, int col) //function overloading
{
    for(int i=0; i<row; i++)
    {
        for(int k =0; k<row; k++)
        {
            cout<<"----";
        }
        for(int j=0; j<col; j++)
        {
            cout<<setw(2)<<grid[i][j]<<" |";
        }
        cout<<endl;
    }
    for(int k =0; k<row; k++)
        {
            cout<<"----";
        }
    cout<<endl;
}

int count_indi(bool** grid, int i, int j, int row, int col)
{
    int count =0;
    for(int k = i-1; k<= i+1; k++)
    {
        for(int l = j-1; l<=j+1; l++)
        {
            if(k<0 || l<0 || k>=row || l >= col || (k == i && l == j) )
                continue;
            else{
                if(grid[k][l])
                    count++;
            }
        }
    }
    return count;
}

int** countmine(bool** grid, int row, int col)
{
    int** new_grid = new int*[row];
    for(int i=0; i<row; i++)
    {
        new_grid[i] = new int[col];
    }

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(grid[i][j])
                new_grid[i][j] = 99;
            else
            {
                int total = count_indi(grid, i, j, row, col);
                new_grid[i][j] = total;
            }
            
        }
    }
    return new_grid;
}

bool haswon(bool** isopen, int** newgrid)
{
    int bombs = 0, opened = 0;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(isopen[i][j])
                opened++;
            if(newgrid[i][j] == 99)
                bombs++;
        }
    }
    return(bombs == (row*col - opened));
}

int main()
{
    bool first_time = true;
    int** new_grid = nullptr;
    bool** isopen = nullptr;
    bool** grid = nullptr;
    srand(time(0));
    int r,c, val;
    bool isover = false;
    ifstream myFile("mine.txt");
    InitWindow(swidth, sheight, "Minesweeper go brrrrrr!");
    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        if(!isover)
        {
            ClearBackground(WHITE);
            if(first_time)
            {
                if(another_first)
                {
                    BeginDrawing();
                    main_menu(swidth, sheight);
                    // first_time = false;
                    EndDrawing();
                }
                else
                {
                    if(choice == 1)
                    {
                        myFile>>row>>col;
                    }
                    isopen = new bool*[row];
                    grid = new bool*[row];
                    for(int i=0; i<row; i++)
                    {
                        grid[i] = new bool[col];
                        isopen[i] = new bool[col];
                    }

                    for(int i=0; i<row; i++)
                    {
                        for(int j=0; j<col; j++)
                        {
                            if(choice ==1)
                                myFile>>val;
                            else   
                            {
                                if(choice2 == 1)
                                {
                                    val = rand()% 10;
                                    if(val == 0)
                                        val = 1;
                                    else    
                                        val = 0;
                                }
                                if(choice2 == 2)
                                {
                                    val = rand()% 8;
                                    if(val == 0)
                                        val = 1;
                                    else    
                                        val = 0;
                                }
                                if(choice2 == 3)
                                {
                                    val = rand()% 6;
                                    if(val == 0)
                                        val = 1;
                                    else    
                                        val = 0;
                                }
                                if(choice2 == 4)
                                {
                                    val = rand()% 5;
                                    if(val == 0)
                                        val = 1;
                                    else    
                                        val = 0;
                                }
                            }
                            grid[i][j] = val;
                            isopen[i][j] = false;
                        }
                    }
                    new_grid = countmine(grid, row, col);
                    first_time = false;
                }
            }
            else
            {
                BeginDrawing();
                print_grid_raylib(new_grid, isopen, row, col);
                EndDrawing();

            // isover = true;

                // cout<<"Enter a place to mine (first row then col): ";
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                    Vector2 mousepos = GetMousePosition();
                    int rx = swidth/col;
                    int ry = sheight/row;

                    r = mousepos.y/ry;
                    c = mousepos.x/rx;
                    // cerr<<r<<" "<<c;
                    // for(int i=0; i<row-1; i++)
                    // {
                    //     for(int j=0; j<col-1; j++)
                    //     {
                    //         if(mousepos.x >= i*rx && mousepos.x < (i+1)*rx && mousepos.y >= j*ry && mousepos.y < (j+1)*ry)
                    //             {

                    //             }
                    //     }
                    // }
                    isopen[r][c] = true;
                    if(grid[r][c])
                    {
                        cout<<"\t\tOops you stepped on a mine \n\t\t Game over!!"<<endl;
                        print_grid(new_grid, row, col);
                        BeginDrawing();
                        print_over_screen();
                        EndDrawing();
                        isover = true;
                    }
                    if(haswon(isopen, new_grid))
                    {
                        BeginDrawing();
                        won_screen();
                        EndDrawing();
                        isover = true;
                    }
                }
            }
            // cin>>r>>c;
        }
    }

    for(int i=0; i<row; i++)
    {
        delete new_grid[i];
        delete grid[i];
        delete isopen[i];
    }
    CloseWindow();
    return 0;
}