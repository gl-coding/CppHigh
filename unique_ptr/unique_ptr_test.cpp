#include <iostream>
#include <memory>

using namespace std;

struct Task {
    int mId;
    Task(int id) :mId(id) {
        cout << "Task::Constructor" << endl;
    }
    ~Task() {
        cout << "Task::Destructor" << endl;
    }
};

int main()
{
    // 通过原始指针创建 unique_ptr 实例
    unique_ptr<Task> taskPtr(new Task(23));

    //通过 unique_ptr 访问其成员
    int id = taskPtr->mId;
    cout << id << endl;

    return 0;
}

