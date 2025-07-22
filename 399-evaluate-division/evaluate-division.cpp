class Solution {
public:
    unordered_map<string, unordered_map<string, double>> graph;

    void buildGraph(vector<vector<string>>& equations, vector<double>& values) 
    {
        for (int i = 0; i < equations.size(); ++i) {
            string src = equations[i][0];
            string dest = equations[i][1];
            double weight = values[i];

            graph[src][dest] = weight;
            graph[dest][src] = 1.0 / weight;
        }
    }

    double dfs(string start, string end, unordered_map<string, bool>& visited) 
    {
        if (graph.find(start) == graph.end() || graph.find(end) == graph.end())
        {
            return -1.0;
        }
        
        if (start == end)
        {
            return 1.0;
        }

        visited[start] = true;
        for (auto neighbor : graph[start]) 
        {
            if (!visited[neighbor.first]) 
            {
                double result = dfs(neighbor.first, end, visited);
                if (result != -1.0)
                {
                    return result * neighbor.second;
                }
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        buildGraph(equations, values);
        vector<double> results;

        for (auto query : queries) 
        {
            string start = query[0];
            string end = query[1];
            unordered_map<string, bool> visited;
            results.push_back(dfs(start, end, visited));
        }

        return results;
    }
};