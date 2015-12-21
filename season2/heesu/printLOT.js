function printLOT(root) { // Level Order Tree
  var queue = [];
  queue.push(root);
  var currentNode;
  while (currentNode = queue.shift()) {
    console.log(currentNode.val);
    queue.push(currentNode.left, currentNode.right);
  }
}


function Node (val, left, right) {
  this.val = val;
  this.left = left;
  this.right = right;
}
var testData = new Node(1, new Node(2, new Node(4, new Node(8), new Node(9)), new Node(5, new Node(10), new Node(11))),
new Node(3, new Node(6, new Node(12), new Node(13)), new Node(7, new Node(14), new Node(15))));
printLOT(testData);
