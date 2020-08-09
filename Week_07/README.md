学习笔记

## 字典树 (Trie) 树的基本实现和特性

> 基本结构

字典树，即 Trie 树，又称单词查找树或键树，是一种树形结构。典型应用是用于统计和排序大量的字符串（但不仅限于字符串），所以经常被搜索引擎系统用于文本词频统计。

它的优点是：最大限度地减少无谓的字符串比较，查询效率比哈希表高。基本结构 AtitoteaintetedteninntAioeadnnn15117341295

> 基本性质

1. 结点本身不存完整单词；
2. 从根结点到某一结点，路径上经过的字符连接起来，为该结点对应的字符串；
3. 每个结点的所有子结点路径代表的字符都不相同。

> 核心思想

Trie 树的核心思想是空间换时间。 利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的。

## 并查集的基本实现、特性

基本操作

- makeSet(s)：建立一个新的并查集，其中包含 s 个单元素集合。
- unionSet(x, y)：把元素 x 和元素 y 所在的集合合并，要求 x 和 y 所在的集合不相交，如果相交则不合并。
- find(x)：找到元素 x 所在的集合的代表，该操作也可以用于判断两个元素是否位于同一个集合，只要将它们各自的代表比较一下就可以了。

```
class unionFind {
  constructor(n) {
    this.count = n;
    this.parent = Array
      .from({ length: n })
      .map((o, i) => i);
  }

  find(p) {
    let root = p;
    while (parent[root] !== root) {
      root = parent[root];
    }
    // 压缩路径
    while (parent[p] !== p) {
      let x = p;
      p = this.parent[p];
      this.parent[x] = root;
    }
    return root;
  }

  union(p, q) {
    let rootP = find(p);
    let rootQ = find(q);
    if (rootP === rootQ) return;
    this.parent[rootP] = rootQ;
    this.count--;
  }
}
```

## 剪枝的实现和特性

1. 朴素搜索
2. 优化方式：不重复（fibonacci）、剪枝（生成括号问题）
3. 搜索方向： DFS: depth first search 深度优先搜索 BFS: breadth first search 广度优先搜索
4. 双向 BFS 搜索、启发式搜索

启发式函数： h(n)，它用来评价哪些结点最有希望的是一个我们要找的结点，h(n) 会返回一个非负实数,也可以认为是从结点 n 的目标结点路径的估计成本。

启发式函数是一种告知搜索方向的方法。它提供了一种明智的方法来猜测哪个邻居结点会导向一个目标。

## AVL 树和红黑树的实现和特性

> AVL 树

- 发明者 G. M. `Adelson-Velsky` 和 `Evgenii Landis`。
- Balance Factor（平衡因子）：是它的左子树的高度减去它的右子树的高度（有时相反）。balance factor = {-1, 0, 1}。
- 通过旋转操作来进行平衡（四种）。
- https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree

旋转操作

1. 左旋
2. 右旋
3. 左右旋
4. 右左旋

AVL 总结

1. 平衡二叉搜索树
2. 每个结点存 balance factor = {-1, 0, 1}
3. 四种旋转操作 AVL

总结不足：结点需要存储额外信息、且调整次数频繁

> Red-black Tree

红黑树是一种近似平衡的二叉搜索树（BinarySearch Tree），它能够确保任何一个结点的左右子树的高度差小于两倍。具体来说，红黑树是满足如下五个条件的二叉搜索树：

- 每个结点要么是红色，要么是黑色
- 根结点是黑色
- 每个叶结点（NIL 结点，空结点）是黑色的。
- 不能有相邻接的两个红色结点
- 从任一结点到其每个叶子的所有路径都包含相同数目的黑色结点。

> AVL 树 和 红黑树 对比

- AVL trees provide `faster lookups` than Red Black Trees because they are `more strictly balanced`.
- Red Black Trees provide `faster insertion and removal` operations than AVL trees as fewer rotations are done due to relatively relaxed balancing.
- AVL trees store balance `factors or heights` with each node, thus requires storage for an integer per node whereas Red Black Tree requires only 1 bit of information per node.
- Red Black Trees are used in most of the `language libraries like map,multimap,multisetin C++` whereas AVL trees are used in `databases` where faster retrievals are required.