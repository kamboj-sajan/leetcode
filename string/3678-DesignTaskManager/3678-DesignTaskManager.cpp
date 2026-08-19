// Last updated: 19/08/2026, 15:26:12
class TaskManager {
    unordered_map<int, pair<int,int>> taskInfo; 
    // taskId -> {userId, priority}
    priority_queue<tuple<int,int,int>> pq; 
    // (priority, taskId, userId), max heap
    
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            taskInfo[taskId] = {userId, priority};
            pq.push({priority, taskId, userId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskInfo[taskId] = {userId, priority};
        pq.push({priority, taskId, userId});
    }
    
    void edit(int taskId, int newPriority) {
        auto [userId, oldPriority] = taskInfo[taskId];
        taskInfo[taskId] = {userId, newPriority};
        pq.push({newPriority, taskId, userId}); 
        // old version stays but will be ignored
    }
    
    void rmv(int taskId) {
        taskInfo.erase(taskId); // heap will clean lazily
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [priority, taskId, userId] = pq.top();
            if (taskInfo.count(taskId) && taskInfo[taskId] == make_pair(userId, priority)) {
                pq.pop();
                taskInfo.erase(taskId);
                return userId;
            }
            pq.pop(); // stale entry
        }
        return -1; // no tasks
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */