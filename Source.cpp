#include<iostream>

using namespace std;


int pageTurning_from_Front(int n, int p) {
    int left_page = 0;
    int right_page = 1;
    int number_of_turns = 0;
    for (int i = 0; i < n; i++) {
        if (left_page == p || right_page == p) {

            break;
        }
        left_page += 2;
        right_page += 2;
        number_of_turns++;
    }
    return number_of_turns;
}

int pageTurning_from_Back(int n, int p) {
    int last_left_page = 0;
    int last_right_page = 0;
    int number_of_turns = 0;
    if (n % 2 == 0) {
        last_right_page = n + 1;
        last_left_page = n;
    }
    else {
        last_right_page = n;
        last_left_page = n - 1;
    }
    for (int i = n; i > 0; i--) {
        if (last_left_page == p || last_right_page == p) {
            break;
        }
        last_right_page -= 2;
        last_left_page -= 2;
        number_of_turns += 1;
    }
    return number_of_turns;
}

int pageCount(int n, int p) {
    int back = pageTurning_from_Back(n, p);
    int front = pageTurning_from_Front(n, p);
    if (back < front) {
        return back;
    }
    else {
        return front;
    }

}



int main() {
    int total_pages, targeted_page;
    cout << "Enter total number of pages : ";
    cin >> total_pages;
    cout << "Enter the targeted page number : ";
    cin >> targeted_page;
    cout << "Number of turns you need to take is/are : " <<pageCount(total_pages, targeted_page);
	return 0;
}