
#include <iostream>
#include<graphics.h>
#include <cstdlib>
#include <windows.h>
#include<conio.h>
using namespace std;
class Jug{
  int capacity;
	int value;

public:

	Jug(int n)

	{
		capacity = n;

		value = 0;

	}

	void Fill()

	{

		value = capacity;

	}

	void Empty()

	{

		value = 0;

	}
	bool isFull()

	{

		return value >= capacity;

	}
	bool isEmpty()

	{

		return value == 0;

	}
	//A[B] -> Transfer contents of B to A until A is full

	void operator[](Jug &B)

	{

		int old_value = value;

		value = value + B.value;

		value = value > capacity?capacity:value;
		B.value = B.value - (value - old_value);

	}
	int getValue()

	{

		return value;

	}

void fillAAA()

{
if(value==1)

{

    rectangle(110,325,240,390);
    setfillstyle(XHATCH_FILL,BLUE);
    floodfill(200,350,WHITE);


}

if(value==2)

{

    rectangle(110,250,240,390);
setfillstyle(XHATCH_FILL,BLUE);
    floodfill(200,300,WHITE);
}

if(value==3)

{

    rectangle(110,175,240,390);
setfillstyle(XHATCH_FILL,BLUE);
    floodfill(200,300,WHITE);
}

if(value==4)

{

    rectangle(110,100,240,390);
setfillstyle(XHATCH_FILL,BLUE);
    floodfill(200,300,WHITE);
}


}
void fillBBB()

{

if(value==1)

{

    rectangle(310,325,440,390);
setfillstyle(XHATCH_FILL,BLUE);
    floodfill(400,350,WHITE);
}

if(value==2)

{

    rectangle(310,250,440,390);
setfillstyle(XHATCH_FILL,BLUE);
    floodfill(400,300,WHITE);
}

if(value==3)

{

    rectangle(310,175,440,390);
    setfillstyle(XHATCH_FILL,BLUE);
    floodfill(400,300,WHITE);

}
getch();
}
};
int gcd(int n,int m)

{

	if(m<=n && n%m == 0)

		return m;

	if(n < m)

		return gcd(m,n);

	else

		return gcd(m,n%m);

}
bool check(int a,int b,int c,int d){

    //boundary cases


	if(c>a||d>b){

		cout<<"Error type again\n";

        return false;

    }

    //if c is multiple of HCF of a and b, then possible

    if(c % gcd(a,b) == 0){

        return true;

    }

    //if c is not multiple of HCF of a and b, then not possible

	cout<<"Can't reach this state with the given jugs\n";

    return false;

}
void drawing()

{

    cleardevice();
    setcolor(YELLOW);
    outtextxy(50,350,"1");
    setcolor(BLUE);
	outtextxy(50,275,"2");
	setcolor(GREEN);
	outtextxy(50,200,"3");
	setcolor(WHITE);
	outtextxy(50,125,"4");
	setcolor(GREEN);
	outtextxy(165,450,"Jug A");
	outtextxy(355,450,"Jug B");
    setcolor(WHITE);
    line(100,100,100,400);
	line(100,400,250,400);
    line(250,400,250,100);

    line(300,175,300,400);
    line(300,400,450,400);
    line(450,400,450,175);
}

void solve(Jug A, Jug B, int result,int resultb,int a,int b)

{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if(a==4&&b==3)
	{

	while(true)

	{
        //Beep(500,1000)
			if(!A.isFull() && B.isEmpty())
		{

			cout<<"\n  Fill B";

			B.Fill();

			//cout << "\t \t \t (A, B) = (" << A.getValue() << ", " << B.getValue() << ")\n";
    SetConsoleTextAttribute(hConsole, 15);
	cout << "\n  (";
    SetConsoleTextAttribute(hConsole, 10);
	cout << "A";
	SetConsoleTextAttribute(hConsole, 15);
	cout <<",";
	SetConsoleTextAttribute(hConsole, 10);
	cout << "B";
	SetConsoleTextAttribute(hConsole, 15);
	cout << ") = (";
	SetConsoleTextAttribute(hConsole, 10);
	cout << A.getValue();
	SetConsoleTextAttribute(hConsole, 15);
	cout << ", ";
	SetConsoleTextAttribute(hConsole, 10);
	cout << B.getValue();
	SetConsoleTextAttribute(hConsole, 15);
	cout << ")\n";
		}

		else if(A.isFull())
		{

			cout<<"\n  Empty A";

			A.Empty();

			//cout << "\t \t \t (A, B) = (" << A.getValue() << ", " << B.getValue() << ")\n";
    SetConsoleTextAttribute(hConsole, 15);
	cout << "\n  (";
    SetConsoleTextAttribute(hConsole, 10);
	cout << "A";
	SetConsoleTextAttribute(hConsole, 15);
	cout <<",";
	SetConsoleTextAttribute(hConsole, 10);
	cout << "B";
	SetConsoleTextAttribute(hConsole, 15);
	cout << ") = (";
	SetConsoleTextAttribute(hConsole, 10);
	cout << A.getValue();
	SetConsoleTextAttribute(hConsole, 15);
	cout << ", ";
	SetConsoleTextAttribute(hConsole, 10);
	cout << B.getValue();
	SetConsoleTextAttribute(hConsole, 15);
	cout << ")\n";
		}

		else

		{

                cout<<"\n  Pour from B into A";

		A[B];
		//cout << "\t \t \t (A, B) = (" << A.getValue() << ", " << B.getValue() << ")\n";
			            	SetConsoleTextAttribute(hConsole, 15);
	cout << "\n  (";
    SetConsoleTextAttribute(hConsole, 10);
	cout << "A";
	SetConsoleTextAttribute(hConsole, 15);
	cout <<",";
	SetConsoleTextAttribute(hConsole, 10);
	cout << "B";
	SetConsoleTextAttribute(hConsole, 15);
	cout << ") = (";
	SetConsoleTextAttribute(hConsole, 10);
	cout << A.getValue();
	SetConsoleTextAttribute(hConsole, 15);
	cout << ", ";
	SetConsoleTextAttribute(hConsole, 10);
	cout << B.getValue();
	SetConsoleTextAttribute(hConsole, 15);
	cout << ")\n";
		}
        if(a==4&&b==3)
		{
		drawing();
        Beep(500,500);
		A.fillAAA();

		B.fillBBB();

		}

		if((A.getValue()==result&&B.getValue()==resultb)||(A.getValue()==0&&B.getValue()==0))

        {

            break;

        }

	}

	if(A.getValue()==0&&B.getValue()==0)

    {
    	system("CLS");

        cout << "\n  Not Possible"<<endl;

    }
    else
		cout<<"\n  !!DONE!!";


}

else
{
	while(true)

	{

			if(!A.isFull() && B.isEmpty())
		{

			cout<<"\n  Fill B";

			B.Fill();

			//cout << "\t \t \t (A, B) = ("<< A.getValue() << ", " << B.getValue() << ")\n";
                	SetConsoleTextAttribute(hConsole, 15);
	cout << "\n  (";
    SetConsoleTextAttribute(hConsole, 10);
	cout << "A";
	SetConsoleTextAttribute(hConsole, 15);
	cout <<",";
	SetConsoleTextAttribute(hConsole, 10);
	cout << "B";
	SetConsoleTextAttribute(hConsole, 15);
	cout << ") = (";
	SetConsoleTextAttribute(hConsole, 10);
	cout << A.getValue();
	SetConsoleTextAttribute(hConsole, 15);
	cout << ", ";
	SetConsoleTextAttribute(hConsole, 10);
	cout << B.getValue();
	SetConsoleTextAttribute(hConsole, 15);
	cout << ")\n";
		}

		else if(A.isFull())
		{

			cout<<"\n  Empty A";

			A.Empty();

			//cout << "\t \t \t (A, B) = (" << A.getValue() << ", " << B.getValue() << ")\n";
                	SetConsoleTextAttribute(hConsole, 15);
	cout << "\n  (";
    SetConsoleTextAttribute(hConsole, 10);
	cout << "A";
	SetConsoleTextAttribute(hConsole, 15);
	cout <<",";
	SetConsoleTextAttribute(hConsole, 10);
	cout << "B";
	SetConsoleTextAttribute(hConsole, 15);
	cout << ") = (";
	SetConsoleTextAttribute(hConsole, 10);
	cout << A.getValue();
	SetConsoleTextAttribute(hConsole, 15);
	cout << ", ";
	SetConsoleTextAttribute(hConsole, 10);
	cout << B.getValue();
	SetConsoleTextAttribute(hConsole, 15);
	cout << ")\n";
		}

		else

		{

                cout<<"\n  Pour from B into A";

		A[B];

		//cout << "\t \t \t (A, B) = (" << A.getValue() << ", " << B.getValue() << ")\n";
        	            	SetConsoleTextAttribute(hConsole, 15);
	cout << "\n  (";
    SetConsoleTextAttribute(hConsole, 10);
	cout << "A";
	SetConsoleTextAttribute(hConsole, 15);
	cout <<",";
	SetConsoleTextAttribute(hConsole, 10);
	cout << "B";
	SetConsoleTextAttribute(hConsole, 15);
	cout << ") = (";
	SetConsoleTextAttribute(hConsole, 10);
	cout << A.getValue();
	SetConsoleTextAttribute(hConsole, 15);
	cout << ", ";
	SetConsoleTextAttribute(hConsole, 10);
	cout << B.getValue();
	SetConsoleTextAttribute(hConsole, 15);
	cout << ")\n";
		}
		if((A.getValue()==result&&B.getValue()==resultb)||(A.getValue()==0&&B.getValue()==0))
        {
            break;
        }

	}

	if(A.getValue()==0&&B.getValue()==0)

    {
        system("CLS");
        cout << "\n  Not Possible"<<endl;

    }


}

}
int main()

{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int a, b, result,resultb;
    int gd=DETECT;
    int gn;
    initgraph( &gd, &gn, "C:\\TC\\BGI" ) ;
    SetConsoleTextAttribute(hConsole, 11);
    cout<<"\t\tWATER JUG\n";
    SetConsoleTextAttribute(hConsole, 15);
	cout<<"\n  Enter capacity of A\n";
    //cout << "";
    SetConsoleTextAttribute(hConsole, 10);
    cout << "  ";
	cin >> a;
	SetConsoleTextAttribute(hConsole, 15);
	cout<<"  Enter capacity of B\n";
    cout << "";
    SetConsoleTextAttribute(hConsole, 10);
    cout << "  ";
	cin >> b;
	do{
    SetConsoleTextAttribute(hConsole, 15);
	cout<<"  Enter required water in A:\n";
    //cout << "\t\t";
    SetConsoleTextAttribute(hConsole, 10);
    cout << "  ";
	cin >> result;
    SetConsoleTextAttribute(hConsole, 15);
	cout<<"  Enter required water in B:\n";
    //cout << "\t\t";
    SetConsoleTextAttribute(hConsole, 10);
    cout << "  ";
	cin >> resultb;
	}

	while(!check(a,b,result,resultb));
	Jug A(a), B(b);
	SetConsoleTextAttribute(hConsole, 15);
	cout << "\n  (";
    SetConsoleTextAttribute(hConsole, 10);
	cout << "A";
	SetConsoleTextAttribute(hConsole, 15);
	cout <<",";
	SetConsoleTextAttribute(hConsole, 10);
	cout << "B";
	SetConsoleTextAttribute(hConsole, 15);
	cout << ") = (";
	SetConsoleTextAttribute(hConsole, 10);
	cout << A.getValue();
	SetConsoleTextAttribute(hConsole, 15);
	cout << ", ";
	SetConsoleTextAttribute(hConsole, 10);
	cout << B.getValue();
    SetConsoleTextAttribute(hConsole, 15);
	cout << ")\n";


	solve(A, B, result,resultb,a,b);

	if(A.getValue()==result&&B.getValue()==resultb)

    {

        cout<<"\n  !!Done!!"<<endl;

    }

	#ifdef _WIN32

	//system("pause");

	#endif
	getch();

	closegraph();

}
