def count_negatives(grid)
    m = grid.size
    n = grid[0].size
    i = 0
    count = 0
    while n > 0 && i < m
        if grid[i][0] < 0
            break
        end
        left = 0
        right = n
        while right > left
            mid = (right + left) / 2
            if grid[i][mid] >= 0
                left = mid + 1
            elsif mid == 0 || grid[i][mid-1] >= 0
                n = mid
                break
            else
                right = mid
            end
        end
        i = i + 1
        count = count + n
    end
    return m*grid[0].size - count
end