class Solution
{
public:
    stack<int> key;
    unordered_set<int> find;
    int n = 0;
    bool canVisitAllRooms(vector<vector<int> > &rooms)
    {
        find.insert(0);
        key.push(0);
        while (!key.empty())
        {
            int room = key.top();
            key.pop();
            for (int a : rooms[room])
                if (!find.count(a))
                {
                    key.push(a);
                    find.insert(a);
                }
            n++;
        }
        return n == rooms.size();
    }
};