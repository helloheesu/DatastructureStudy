function countNodes (root) {
  var count = 0;
  var stack = [];
  if (!root) {
  	return 0;
  }
  stack.push(root);
  var currentNode;
  while (stack.length > 0) {
  	count++;
  	currentNode = stack.pop();
  	if (currentNode.left) stack.push(currentNode.left);
  	if (currentNode.right) stack.push(currentNode.right);
  }
  return count;
}

function countInternalNodes (root) {
	var count = 0;
	var stack = [];
	stack.push(root);
	var currentNode;
	while (stack.length > 0) {
		currentNode = stack.pop();
		if (!currentNode || (!currentNode.left && !currentNode.right)) {
			continue;
		}
		count++;
		stack.push(currentNode.left, currentNode.right);
	}
	return count;
}


var root = {
	val:null
};

var node1 = {val:1}, 
node2 = {val:2},
node3 = {val:3},
node4 = {val:4},
node5 = {val:5},
node6 = {val:6},
node7 = {val:7},
node8 = {val:8},
node9 = {val:9},
node10 = {val:10};

node1.left = node2;
node1.right = node3;
node2.left = node4;
node2.right = node5;
node3.left = node6;
node3.right = node7;
node5.left = node8;
node6.right = node9;
node7.left = node10;

var root = node1;

countNodes(root);

countInternalNodes(root);



function sortLast(array) {
	var len = array.length;
	var lastElement = array[len-1];
	for (var prePos = len-2; prePos >= 0 && array[prePos] > lastElement; prePos--) {
		array[prePos+1] = array[prePos];
	}
	array[prePos+1] = lastElement;
	return array;
}

var t = [1,7,9,10,20,30,8];
console.log(t);
console.log(sortLast(t));
