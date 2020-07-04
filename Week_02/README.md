# 学习笔记

## 一. 哈希表，映射，集合

+ map：键值对, key不重复

+ set:  不重复元素的集合

  map set底层用 哈希表或二叉树等实现, 哈希表 又叫散列表 根据关键码值直接访问的数据结构

  哈希函数 查询，添加，删除 时间复杂度 如果碰撞处理得好则 O(1)

  哈希表较小时冲突处理得不好，退化成链表 时间复杂度退化为O(n)


----

### 面试4件套：

+ 1.和面试官把题目过一遍

+ 2.从多种题解中找出最优的解法（时间空间复杂度）

+ 3.写代码

+ 4.测试样例阐述

----

## 二. 树，二叉树，二叉搜索树

+ 回顾一维数据结构 优化方法:升维

+ 二维数据结构：树 图

+ 树和图的差别： 有无环

+ 链表是特殊化的树 ，树是特殊化的图
  
+ 结点定义代码：python：

  class TreeNode:
  + def __init__(self, val):
    +         self.val = val
    +         self.left, self.right = None, None


### 树的遍历

+ 1.前序 根左右

+ 2.中序 左根右

+ 3.后序 左右根


----

+ 二叉搜索树（二叉排序树), 排好序后维护起来更加高效

+ 二叉搜索树常见操作：

  1.查询  O(logn)

  2.插入新结点（新建）O(logn)

  3.删除 O(logn)

  二叉搜索树比单链表 O(n) 要快

+ 二叉树遍历代码模板（python）：递归

  def preorder(self, root)

  + if root:

    + self.traverse_path.append(root.val)

    +         self.precoder(root.left)

    + self.precoder(root.right)

  def inorder(self, root)

  + if root:

    +         self.inorder(root.left)

    +         self.traverse_path.append(root.val)

    + self.inorder(root.right)

  def postorder(self, root)

  + if root:

    + self.postorder(root.left)

    + self.postorder(root.right)

    +         self.traverse_path.append(root.val)


----

## 三.堆和二叉堆，图

+ 堆 ：在一堆数据能快速找到最大 或 最小者 二者只能取其一

+ 假设是大顶堆，常见操作：

  find_max:  O(1)

  delete_max: O(logn)

  insert(create)：O(logn) 或 O(1)





+ 堆的实现有很多种，二叉堆是堆（优先队列）的一种常见且简单的实现，但并不是最优的实现

+ 二叉堆删除插入操作效率并不高O(logn) 

+ 大顶堆：   

  通过完全二叉树实现

  树中任意结点的值总是大于其子节点的值

+ 二叉堆一般通过数组实现：

  假设第一个元素在数组中索引为0的话，则父节点和子节点的关系如下：

  索引为i的左孩子的索引为2i + 1 

  索引为i的右孩子的索引为2i + 2

  索引为i的父节点的索引为 floor((i - 1) / 2)

  

+ 插入最大元素:heapifyUp

  1.新元素先插入堆的尾部

  2.依次向上调整堆的结构（一直到根即可）

  

+ 删除最大元素： heapifyDown

  1.将堆尾元素替换到顶部

  2.依次从根部向下调整整个堆的结构 （一直到堆尾即可）

  

+ 图：Graph(V, E)

  

  V-vertex ：点

  1.度-入度和出度  与点连接的边的个数    

  2.点与点之间：连通与否

  

  E-edge: 边

  1.有向和无向（单行线）

  2.权重（边长）

