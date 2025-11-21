#include"algorithms.hpp"
#include<queue>

static int pipe_id = -1;
static int get_pipe_id(){
    return pipe_id--;
}

vec2 get_image_dimensions(const char* str){
    SDL_Surface* surf = IMG_Load(str);
    vec2 result(surf->w*house_scale,surf->h*house_scale);
    SDL_DestroySurface(surf);

    return result;
}

vec2 coord_to_idx(int x,int y){
    vec2 house_dim = get_image_dimensions(house_texture);

    float col = (x + house_dim.x / 2) / mapscale;
    float row = (y + house_dim.y / 2) / mapscale;

    if (row >= 0 && row < maprows && col >= 0 && col < mc)return {row,col};
    else return {-1.f,-1.f};
}

int house_clicked(vec2 coords,std::vector<object*>& houses){
    vec2 h_dimenstion = get_image_dimensions(house_texture);
    for(int i=0;i<houses.size();i++){
        if(coords.x > houses[i]->position.x && coords.x < houses[i]->position.x + h_dimenstion.x){
            if(coords.y > houses[i]->position.y && coords.y < houses[i]->position.y + h_dimenstion.y) return i;
        }
    }
    return -1;
}

void connect(u_graph& game,const std::vector<int>& chosen,std::vector<std::vector<int>>& map,std::vector<object*>& objects,std::vector<pipe*> pipes){
    game.make_connections(chosen[0],chosen[1]);
    int pipe = get_pipe_id();
    pathfind(map,(int)objects[chosen[0]]->map_pos.x,(int)objects[chosen[0]]->map_pos.y,(int)objects[chosen[1]]->map_pos.x,(int)objects[chosen[1]]->map_pos.y,pipe);
    game.add_node('p',pipe);
    // game.make_connections(pipe,chosen[0],chosen[1]);
    std::cout<< "connecting: " << (int)objects[chosen[0]]->map_pos.x << ' ' << (int)objects[chosen[0]]->map_pos.y << ' ' << (int)objects[chosen[1]]->map_pos.x << ' ' << (int)objects[chosen[1]]->map_pos.y << '\n';
}

bool isValid(int x, int y,
             int start_x, int start_y,
             int target_x, int target_y,
             const vector<vector<int>> &maze,
             const vector<vector<bool>> &visited)
{
    int n = maze.size(), m = maze[0].size();

    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;

    // Allow start and target cells even if they are '1'
    if ((x == start_x && y == start_y) || (x == target_x && y == target_y))
        return !visited[x][y];

    // Everything else must not be 1 and not visited
    return (maze[x][y] != 100 && !visited[x][y]);
}

void pathfind(vector<vector<int>> &maze, int start_x, int start_y, int target_x, int target_y,int mark){
    int n = maze.size(), m = maze[0].size();

    // Directions: up, down, left, right
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;

    bool found = false;

    while (!q.empty())
    {
        pair<int, int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
        q.pop();


        if (x == target_x && y == target_y)
        {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny, start_x, start_y, target_x, target_y, maze, visited)) {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    if (!found)
    {
        cout << "No path found.\n";
        return;
    }

    // Mark path with 2
    pair<int, int> curr = {target_x, target_y};
    while (curr.first != -1)
    {
        maze[curr.first][curr.second] = mark;
        curr = parent[curr.first][curr.second];
    }

    // // Print maze with path
    // cout << "Maze with path marked (2 = path):\n";
    // for (auto &row : maze)
    // {
    //     for (auto &cell : row)
    //         cout << cell << " ";
    //     cout << "\n";
    // }
}
