def dfs(adj, lengths, i)
        if lengths[i] != 0 
            return 
        end
        if adj[i].size == 0
            lengths[i] = 1
        else
            max_len = 0
            adj[i].each do |j| 
                dfs(adj, lengths, j)
                if max_len < lengths[j]
                    max_len = lengths[j]
                end
            end
            lengths[i] = max_len + 1
        end
    end

def max_jumps(arr, d)
    adj = Array.new(arr.size) {Array.new}
    0.upto(adj.size - 1) do |i|
        1.upto(d) do |j|
            if i + j < adj.size and arr[i] > arr[i+j]
                adj[i].push(i+j)
            else
                break
            end
        end
        1.upto(d) do |j| 
            if i - j >= 0 and arr[i] > arr[i-j]
                adj[i].push(i-j)
            else
                break
            end
        end
    end
    
    lengths = Array.new(adj.size, 0)
    
    0.upto(adj.size - 1) do |i| 
        dfs(adj, lengths, i)
    end
    
    lengths.max
end