#pragma once

int generateId(){
static int c=0;
return ++c;
}

struct ToDoTask{
public:
    int id;
    std::string title;
    int priority;
    std::string description;
    ToDoTask()=default;
    ToDoTask(const std::string& t,const int& p, const std::string& desc){
    id=generateId();
    title=t;
    priority=p;
    description=desc;
    }
};



