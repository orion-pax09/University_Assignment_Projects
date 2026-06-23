#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Tic_Tac_Toe{
    private:
    int N;
    char**array;
    char symbol;
    int movecount;
    public:
    void allocate(){
        array=new char*[N];
        for (int i = 0 ; i < N ; i++){
            array[i] = new char[N];
            for (int j = 0 ; j < N ; j++){
                array[i][j] = '-';
            }
        }
    }
    Tic_Tac_Toe():N(3), symbol('X') , movecount(0){
        allocate();
    }
    Tic_Tac_Toe(int n , char sym):N(n>0?n:3), symbol(sym) , movecount(0){
        allocate();
    } 
    void deallocate(){
        for (int i = 0 ; i < N ; i++){
            delete[]array[i];
        }
        delete[]array;
        array=nullptr;
    }
    Tic_Tac_Toe(const Tic_Tac_Toe&other):N(other.N) , symbol(other.symbol),movecount(other.movecount){
        array= new char*[N];
        for (int i = 0 ; i < N ; i++){
            array[i] = new char[N];
            for (int j = 0 ; j < N ; j++){
                array[i][j] = other.array[i][j];
            }
        }
    }
    ~Tic_Tac_Toe(){
        if(array!=nullptr){
            cout<<"------Deallocated------"<<endl;
            deallocate();
        }
        array=nullptr;

    }
    friend ostream&operator<<(ostream&out , const Tic_Tac_Toe&game){
        out<<"\n";
        for (int i = 0; i < game.N; i++) {
            out << " ";
            for (int j = 0; j < game.N; j++) {
                out << game.array[i][j];
                if (j < game.N - 1) out << " | ";
            }
            out << "\n";
            if (i < game.N - 1){
                for (int k = 0 ; k < game.N ; k++){
                    out<<"---";
                    if (k < game.N-1){
                        out<<"+";
                    }
                }
                out<<"\n";
            }
        }
        return out;
    }
 friend ofstream& operator<<(ofstream& out, const Tic_Tac_Toe& game){
        out << game.N << "\n";
        out << game.symbol << "\n";
        out << game.movecount << "\n";
        for (int i = 0; i < game.N; i++) {
            for (int j = 0; j < game.N; j++)
                out << game.array[i][j] << " ";
        }
            out << "\n";
        return out;
    }

    friend ifstream& operator>>(ifstream&in , Tic_Tac_Toe&game){
        int n;
        in>>n;
        in>>game.symbol;
        in>>game.movecount;
        game.deallocate();
        game.N = n;
        game.allocate();
        for (int i = 0 ; i < game.N ; i++){
            for (int j = 0 ; j < game.N ; j++){
                in>>game.array[i][j];
            }
        }
        return in;
    }
    void saveGame(const string&filename = "BasicGame.txt")const{
        ofstream file(filename);
        if(!file){
            cout << "Error: could not open file for saving"<<endl;
            return;
        }
        file<<*this;
        cout << "Game saved to"<< filename<<endl;
    }
    bool loadGame(const string&filename="BasicGame.txt"){
        ifstream file(filename);
        if(!file){
            cout<< "No game found"<<endl;
            return false;
        }
        file>>*this;
        cout << "Game loaded from "<<filename<<endl;
        return true;
    }
    //---------------------------------------symbol function------------------------------------------------
    void setsymbol(){
        char Symbol;
        cout << "Enter the symbol: ";
        while (true){
            cin>>Symbol;
            if (Symbol=='X'||Symbol=='x'){
               symbol = 'X';
                break;
            }
            else if (Symbol=='O'||Symbol=='o'){
                symbol = 'O';
                break;
            }
            else{
                cout << "Invalid.Enter either X or O"<<endl;
            }
        }
    }
    char getsymbol(){
        return symbol;
    }
    //----------------------------------check move boundary function-----------------------------------

    bool isvalidmove(int Rows , int Cols){
        if (Rows <0 || Rows >=N || Cols < 0 || Cols >=N){
            cout << "Out of bounds! Rows and Columns must be between 0 and "<<N-1<<endl;
            return false;
        }
        if (array[Rows][Cols]!='-'){
            cout << "Cell is already occupied.Choose an empty cell"<<endl;
            return false;
        
        }
        return true;
    }

    //---------------------------------check input move function-------------------------------------
    bool setindex(){
        int rows;
        int cols;
        while (true){
            cout << "Enter the rows (0 to  "<<N-1<<"): "<<endl;
            cout<< "Enter -1 -1 to quit"<<endl;
            if (!(cin>>rows)){
                cout << "Invalid.Enter the correct rows number: ";
                cin.clear();
                cin.ignore(1000,'\n');
                continue;
            }
            cout << "Enter the column (0 to  "<<N-1<<"): "<<endl;
            if(!(cin>>cols)){
                cout << "Enter the correct column number: ";
                cin.clear();
                cin.ignore(1000,'\n');
                continue;
                
            }
            if (rows == -1 && cols==-1){
                saveGame();
                return false;
            }
            if (isvalidmove(rows  , cols)){
                array[rows][cols] = symbol;
                movecount++;
                break;
            }
            cout << "Invalid. Try again"<<endl;
        }
        return true;
    }
    //----------------------------making function to switch player turns------------------------------
    void switchturns(){
        symbol=(symbol=='X'?'O':'X');
    }
    //-----------------------------making function of all moves validation----------------------------

    bool diagonalcheck(){
        bool maindiagonal = true;
        for (int i = 0 ; i < N ; i++){
            if(array[i][i]!=symbol){
                maindiagonal = false;
                break;
            }
        }
        if (maindiagonal){
            return true;
        }
        return false;
    }

    bool antidiagonal(){
        bool antidiagonal = true;
        for (int i = 0 ; i < N ; i++){
            if (array[i][N-i-1]!=symbol){
                antidiagonal=false;
                break;
            }
        }
        if (antidiagonal){
            return true;
        }
        return false;
    }

    bool check_rows(){
        for (int i = 0 ; i < N ; i++){
            bool rows_check=true;
            for (int j = 0 ; j < N ; j++){
                if (array[i][j]!=symbol){
                    rows_check=false;
                    break;
                }
            }
            if (rows_check){
                return true;
            }
        }
        return false;
    }

    bool check_cols(){
        for (int i = 0 ; i < N ; i++){
            bool cols_check = true;
            for (int j = 0 ; j < N ; j++){
                if (array[j][i]!=symbol){
                    cols_check=false;
                    break;
                }
            }
            if (cols_check){
                    return true;
                }
        }
        return false;
    }
    //-----------------------making function to decide winner-------------------------

    bool winnercheck(){
        bool checkwin=false;
        if (diagonalcheck()||antidiagonal()||check_rows()||check_cols()){
            checkwin=true;
        }
        return checkwin;
    }
    bool drawcheck(){
        bool checkwin=false;
        if (movecount==N*N && !(winnercheck())){
            checkwin=true;
        }
        return checkwin;
    }
    //----------------------making a function to play tic tac toe after making all function------------------------

    int getmoves(){
        return movecount;
    }

    void play(){
        cout<<"----------Tic Tac Toe----------"<<endl;
        cout<< "Board size "<<N<<"X"<<N<<endl;
        cout<< "Player X VS Player O"<<endl;
        while (true)
        {
            cout<<*this;
            bool move = setindex();
            if (!move){
                cout<<"Game is ended"<<endl;
                break;
            }
            if (winnercheck()){
                cout<<*this;
                cout<< "----------Congratulation! Player "<<symbol<<" wins.--------"<<endl;
                return;
            }
            if (drawcheck()){
                cout<< "----It's a draw. Well played----"<<endl;
                return;
            }
            switchturns();
            cout<<"Total moves: "<<getmoves()<<endl;
        }
    }
};
int main(){
    int button;
    cout << "Enter the choice: "<<endl;
    cout <<"Enter 1 to start new game 3x3"<<endl;
    cout <<"Enter 2 to play game board of any size"<<endl;
    cout<< "Enter 3 to load and save game"<<endl;
    do
    {
        cin>>button;
        if (button < 1 || button > 3){
            cout<<"Invalid. Enter the following choice from 1 to 3 ";
            cin.clear();
            cin.ignore(1000,'\n');
        }
        else if (button==1){
            Tic_Tac_Toe game;
            game.play();
            cout<<"total move played: "<<game.getmoves()<<endl;

        }
        else if (button==2){
            int Num;
            cout << "Enter the grid size you want to play: ";
            cin>>Num;
            Tic_Tac_Toe game(Num , 'X');
            game.play();
        cout<<"total move played: "<<game.getmoves()<<endl;
        }
        else{
            Tic_Tac_Toe game;
            if(game.loadGame()){
                game.play();
                cout<<"total move played: "<<game.getmoves()<<endl;
                
            }
            else{
                cout<<"Starting new game 3x3 instead"<<endl;
                game.play();
                cout<<"total move played: "<<game.getmoves()<<endl;
                
            }
        }
    } while (false);
    return 0;
}
