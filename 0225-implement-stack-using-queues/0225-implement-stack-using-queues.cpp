class MyStack {
public:
    queue<int> q;

    MyStack() {}

    void push(int x) {
        q.push(x);
    }

    int pop() {
        queue<int> temp;

        while (q.size() != 1) {
            temp.push(q.front());
            q.pop();
        }

        int num = q.front();
        q.pop();

        while (!temp.empty()) {
            q.push(temp.front());
            temp.pop();
        }

        return num;
    }

    int top() {
        queue<int> temp;

        while (q.size() != 1) {
            temp.push(q.front());
            q.pop();
        }

        int num = q.front();
        temp.push(q.front());
        q.pop();

        while (!temp.empty()) {
            q.push(temp.front());
            temp.pop();
        }

        return num;
    }

    bool empty() {
        return q.empty();
    }
};