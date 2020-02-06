let getSumOfTree = function(root) {
    if(root.sum != undefined) {
        return
    } else {
        if(root.left != null && root.right != null) {
            getSumOfTree(root.left)
            getSumOfTree(root.right)
            root.sum = root.left.sum + root.right.sum + root.val
        } else if(root.left == null && root.right == null) {
            root.sum = root.val 
        } else if(root.left == null) {
            getSumOfTree(root.right)
            root.sum = root.right.sum + root.val
        } else {
            getSumOfTree(root.left)
            root.sum = root.left.sum + root.val
        }
    }
};

let findTheSubtree = function(root, bestVal) {
    mostCloseVal = Infinity
    let treeWalk = function(node) {
        if(Math.abs(mostCloseVal - bestVal) > Math.abs(node.sum - bestVal)) {
            mostCloseVal = node.sum
        }
        if(node.left != null) treeWalk(node.left)
        if(node.right != null) treeWalk(node.right)
    };
    treeWalk(root)
    return mostCloseVal
};

var maxProduct = function(root) {
    getSumOfTree(root)
    sumOfAll = root.sum
    bestVal = sumOfAll / 2
    mostCloseVal = findTheSubtree(root, bestVal)
    return (mostCloseVal * (sumOfAll - mostCloseVal)) % (1e9 + 7)
};