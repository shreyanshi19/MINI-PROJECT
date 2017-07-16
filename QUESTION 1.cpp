/*                                              MINI PROJECT 2017
                                                 Question no.- 1

                         Submitted by-
                                      Shreyanshi Arun           (CS&CC)
                                      Smitha Dinesh Semwal      (CS-D)

 */

#include<iostream>
using namespace std;

int main()
{
    int N, i, j;                                                            //  N = size of matrix
    bool connected1=false, connected2=false;
    char choice;

    resume : cin >> N;

     if( N < 1 || N > 100 )

             {

                cout << "INVALID INPUT\n";
                cout << "DO you want to continue ? press Y/N"<<endl;
                cin >> choice;
                cin.ignore();

                if(choice == 'y' || choice == 'Y')
                    goto resume;

                else
                    return 0;
             }

    int **matrix = new int*[N];                                         //  Dynamic allocation of memory for matrix

    for(i=0; i<N; i++)
        matrix[i] = new int[N];


    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {

            cin >> matrix[i][j];

            if( matrix[i][j] !=0 && matrix[i][j] != 1 && matrix[i][j] != 2)
             {

                cout << "INVALID INPUT\n";
                cout << "DO you want to continue ? press Y/N"<<endl;
                cin >> choice;
                cin.ignore();

                if(choice == 'y' || choice == 'Y')
                    goto resume;

                else
                    return 0;
             }
        }
    }


    for(i=0; i<N; i++)                                               //     CONVERT FIRST ROW 1's INTO 'a'
    {
        if(matrix[0][i] == 1)
        {
           matrix[0][i] = 'a';
        }

    }

    for(i=0; i<N; i++)                                              //     CONVERT FIRST COLUMN 2's INTO 'b'
    {
        if(matrix[i][0] == 2)
        {
            matrix[i][0] = 'b';
        }
    }

    for(i=0; i < N-1; i++)                                         //      SEARCH FOR LOWER ADJACENT 1's AND CONVERT THEM INTO 'a'
    {
        for(j=0; j<N; j++)
        {
            if(matrix[i][j] == 'a')
            {

                if ( i+1 < N && matrix[i+1][j] == 1)               //      SOUTH ADJACENT 1
                {
                    matrix[i+1][j] = 'a';
                }

                if (i+1 < N && j-1 >= 0 && matrix[i+1][j-1] == 1)  //      SOUTH WEST ADJACENT 1
                {
                    matrix[i+1][j-1] = 'a';
                }

                if (i+1 < N && j+1 < N && matrix[i+1][j+1] == 1)   //      SOUTH EAST ADJACENT 1
                {
                    matrix[i+1][j+1] = 'a';
                }
            }
        }
    }

    for(j=0 ; j<N ; j++)                                           //      SEARCH 'a' IN LAST ROW
    {
        if (matrix[N-1][j] == 'a')
        {
            connected1 = true;                                     //      IF 'a' FOUND. 1's connected
            break;
        }
    }

    for(i=0; i<N-1; i++)
    {
        for(j=0; j<N; j++)
        {
            if(matrix[j][i] == 'b')                                //     SEARCH FOR LOWER ADJACENT 2's AND CONVERT THEM INTO 'b'
            {
                if (i+1 < N && matrix[j][i+1] == 2)
                {
                    matrix[j][i+1] = 'b';                          //     EAST ADJACENT 2
                }

                if (i+1 < N && j-1 >= 0 && matrix[j-1][i+1] == 2)
                {
                    matrix[j-1][i+1] = 'b';                        //     NORTH EAST ADJACENT 2
                }

                if (i+1 < N && j+1 < N && matrix[j+1][i+1] == 2)
                {
                    matrix[j+1][i+1] = 'b';                        //     SOUTH EAST ADJACENT 2
                }
            }
        }
    }

    for(j=0; j<N; j++)
    {
        if (matrix[j][N-1] == 'b')                                 //     SEARCH 'b' IN LAST COLUMN
        {
            connected2 = true;                                     //     IF 'b' FOUND. 2's CONNECTED
            break;
        }
    }



     if(connected1 == true)
    {
        cout << "1" << endl;                                       //     IF 1's CONNECTED. PRINT "1"
    }

     else if (connected2 == true)
    {
        cout << "2" << endl;                                       //     IF 2's CONNECTED. PRINT "2"
    }

    if(connected1 == true && connected2 == true)
    {
        cout << "AMBIGUOUS" << endl;                               //     IF 1's AND 2's BOTH CONNECTED. PRINT "AMBIGUOUS"
    }

   else
    {
        cout << "0" << endl;                                       //     IF NEITHER 1's NOR 2's CONNECTED. PRINT "0"
    }

    return 0;                                                      //     END OF CODE
}

