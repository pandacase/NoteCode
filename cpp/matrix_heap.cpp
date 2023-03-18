#include<iostream>
using namespace std;
const int MAXN = 100010;

class array {
private:
	int elem[MAXN];
public:
	int &operator[](int i) { return elem[i]; }
};

class heap {
private:
	int n;
	array h;
public:
	void clear() { n = 0; }
	int top() { return h[1]; }
	int size() { return n; }
	void push(int);
	void pop();
};

void swap(array h, int i, int j){
	int temp = h[i];
	h[i] = h[j];
	h[j] = temp;
}

void heap::push(int data){
	h[n+1] = data;
	++n;
	for(int i = n; i/2 > 0; i = i/2){
		if( h[i] < h[i/2] ) swap(h, i, i/2);
	}
}

void heap::pop(){
	h[1] = h[n];
	--n;

	int minpos = 1;
	while(1){
		int i = minpos;
		if(2*i <= n && h[2*i] < h[i]) minpos = 2*i;
		if(2*i+1 <= n && h[2*i+1] < h[minpos]) minpos = 2*i+1;
		if(i == minpos) break;
		else swap(h, i, minpos);
	}
}


int main(){
	heap h;
	h.push(3);
	h.push(1);
	h.push(2);
	h.push(-4);
	h.push(4);
	h.push(5);
	printf("%d\n", h.top());
	h.pop();
	printf("%d\n", h.top());
	return 0;
	system("pause");
}
