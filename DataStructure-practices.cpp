/* 
* 此为数据结构课程练习题。
* 习题来源《数据结构习题集》严蔚敏著，清华大学出版社。
* 第2、3、5、6、7、9章练习题及部分讨论题。
* 练习题及讨论题文档另存放于百度网盘。
*/
// 讨论题 2-4
void delete(Linklist &L) {
    // 有头节点。
    Linklist *p = L->next, ans, previous = L;
    ans = p;
    while (p->next) {
        if (p->next->data < ans->data) {
            previous = p;
            ans = p->next;
        }
        p = p->next;
    }
    previous->next = ans->next;
    free(ans);
}
// 讨论题 2-5
void josephCircle(Polyn *p, int n, int m) { // p是一个循环链表
    Polyn *p1, *p2;
    p1 = p;
    for (int i = 1; i < m; ++i) {   // 一次死掉一个人，最后剩一个
        for (int j = 1; j < n; ++j) {
            p1 = p1->next;
        }
        cout << p1->data;
        n = p1->psw;
        p2 = p1->next;
        p1->next = p1->next->next;
        free(p2);
    }
}
// 练习题 2-11
Status InsertOrderedList(SqList &a, ElemType x) {
    if (a.length == a.listsize) {
        return (OVERFLOW);
    } else {
        i = a.length - 1;
        while (i >= 0 && x < a.elem[i]) {
            --i;
        }
        for (j = a.length - 1; j >= i + 1; --j) {
            a.elem[j + 1] = a.elem[j];
        }
        a.elem[j + 1] = x;
        ++a.length;
        return OK;
    }
}
// 练习题 2-12
Status CompareList(SqList &a, SqList &b) {
    m = a.length;
    n = b.length;
    while (i <= m && i <= n) {
        if (a.elem[i] < b.elem[i]) {
            return (A < B);
        } else if (a.elem[i] > b.elem[i]) {
            return (A > B);
        }
        ++i;
    }
    if (i == m && m < n) {
        return (A < B);
    } else if (i == n && n < m) {
        return (A > B);
    } else if (i == m && m == n) {
        return (A = B);
    }
}
// 练习题 2-14
int Length(SqList &p) {
    p = p->next;
    n = 0;
    while (p) {
        ++n；
        p = p->next;
    }
    return n;
}
// 练习题 2-15
ListNode* Linklist(ListNode *ha, ListNode *hb， int m, int n) {
    if (m <= n) {   // a表比较短，应把 b 表连接到 a 
        ha = ha->next;
        while (ha) {
            ha = ha->next;
        }
        ha->next = hb->next;
        free(hb);
        return ha;
    } else {
        hb = hb，->next;
        while (hb) {
            hb = hb->next;
        }
        hb->next = ha->next;
        free(ha);
        return hb;
    }
}
时间复杂度：O(min(m, n))
// 练习题 2-19
void DeleteList(ListNode *a, double mink, double maxk) {
    if (mink >= maxk) {
        return ERROR;
    }
    ListNode *pre, *cur, *temp;
    pre = a;
    cur = a->next;
    while (cur->next) {
        if (cur->data > mink && cur->data < maxk) {
            pre->next = cur->next;
            temp = cur;
            cur = cur->next;
            free(temp);
        } else {
            pre = cur;
            cur = cur->next;
        }
    }
}
// 练习题 2-21
int a, b;   // 互换位置
a = a + b;
b = a - b;
a = a - b;
void ReverseList(SqList &a) {
    m = a.length;
    for (i = 0; i <= m / 2 - 1; ++i) {
        a[i] = a[i] + a[m - 1 - i];
        a[m - 1 - i] = a[i] - a[m - 1 - i];
        a[i] = a[i] - a[m - 1 - i];
    }
}
// 练习题 2-22
// 头插法
ListNode* ReverseList(ListNode *head) {
    ListNode *p, *q;
    p = head->next;
    head->next = NULL;
    while (p != NULL) {
        q = p;
        p = p->next;

        q->next = head->next;
        head->next = q;
    }
   return head;
}
// 递归法
ListNode* ReverseList(ListNode *head) {
    if (head == NULL || head->next == NULL) { // 空表
        return a;
    }
    /*递归*/
    ListNode* headOfReverse = ReverseList(head->next);
    /*回溯：将当前表头结点链接到逆序链表的尾部*/
    head->next->next = head;
    head->next = NULL;
    return headOfReverse;
}
// 练习题 2-24
void MergeList(ListNode *&a, ListNode *&b, ListNode *&n) {
	//新链表递减排列，故可以采用头插法-假设均带头节点 
	ListNode *p = a->next, *q = b->next, *r, *m;
	r = n = a;
	r->next = NULL;
	free(b);
	while (p != NULL and q != NULL) {
		if (p->num < q->num) {
			m = p->next;
			p->next = r->next;
			r->next = p;
			p = m;
		} else {
			m = q->next;
			q->next = r->next;
			r->next = q;
			q = m;
		}
	} 
	while (p != NULL) {
		m = p->next;
		p->next = r->next;
		r->next = p;
		p = m;
	}
	while (q != NULL){
		m = q->next;
		q->next = r->next;
		r->next = q;
		q = m;
	}
}
// 练习题 2-33
void Classification(ListNode *p) {
    ListNode *n, *l, *pre, *cur, *temp;
    n = nn = new ListNode;
    l = ll = new ListNode;

    pre = p;
    cur = p->next;
    p = p->next;
    while (p) {
        pre->next = cur->next;
        temp = cur;
        cur = cur->next;
        if (temp->data == numberChar) {
            n->next = temp;
            temp->next = NULL;
            n = temp;
        } else if (temp->data == lettersChar) {
            l->next = temp;
            temp->next = NULL;
            l = temp;
        }
    }
    p->next = p;
    n->next = nn;
    ll->next = ll;
}
// 练习题 3-5
一般准则：假设给定序列长度为Length，则有
①第一个操作为入栈S；②最后一个操作为出栈X；③对任意的i（1<=i<=Length）,从1到i，S的个数>=X的个数；④对整个序列，X的个数=S的个数；
证明：假设前N个序列相等，第N+1个序列不同。不妨设A的第N+1个为S，B的第N+1个为X，则相应的输出序列必然不同。所以原命题成立。
// 练习题 3-6
证明：假设存在着i<j<k,使得pj<pk<pi。如果i<j，则对于pi<pj的情况，说明pi在pj入栈前出栈。而对于pi>pj的情况，则说明要将pj压到pi之上，
也就是说在pj出栈之后pi才能出栈。与假设不符。∴假设不成立。
// 练习题 3-17
Status Distinguish() {
    InitStack(S);
    ch = getchar();
    flage = 0;
    while (ch != '@') {
        if (ch == '&') {
            flage = 1;
            continue;
        }
        if (flage != 1) 
            Push(S, ch);
        else {
            Pop(S, e);
            if (e != ch) return NO;
        }
        ch = getchar();
    }
    ClearStack(S);
    if (flage != 1) return NO;
    else return OK;
}
// 练习题 3-19
Status Pair(SqList &str) {
    InitStack(S);
    for (int i = 0; i < str.Length; ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') 
            Push(S, str[i]);
        if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (StackEmpty(S)) return NO;
            Pop(S, e);
            if (str[i] == ')')
                if (e != '(') 
                    return NO;
            if (str[i] == '[')
                if (e != ']') 
                    return NO;
            if (str[i] == '{')
                if (e != '}') 
                    return NO;
        }
    }
    if (StackEmpty(S)) 
        return OK;
    else {
        ClearStack(S);
        return NO;
    }
}
// 3-21
char *RPExpression(char *e) {
     //栈s1用于存放运算符，栈s2用于存放逆波兰式
    Stack s1,s2;
    InitStack(s1);
    InitStack(s2);
   
    //假设字符'#'是运算级别最低的运算符，并压入栈s1中
    Push(s1,'#');
    //p指针用于遍历传入的字符串，ch用于临时存放字符,length用于计算字符串长度 
    char *p=e,ch;
    int length=0;
    for(;*p!='\0';p++) { //逐个字符访问
       switch(*p) {
           //遇'('则直接入栈s1
           case '(':
               Push(s1,*p);
               break;
           //遇')'则将距离栈s1栈顶的最近的'('之间的运算符，逐个出栈，依次送入栈s2,此时抛弃'('
           case ')':
                while(Top(s1)!='(') 
                {
                   Pop(s1,ch);
                   Push(s2,ch);
                }
               Pop(s1,ch);
               break;
           //遇下列运算符，则分情况讨论：
           //1.若当前栈s1的栈顶元素是'('，则当前运算符直接压入栈s1；
           //2.否则，将当前运算符与栈s1的栈顶元素比较，若优先级较栈顶元素大，则直接压入栈s1中,
           //  否则将s1栈顶元素弹出，并压入栈s2中，直到栈顶运算符的优先级别低于当前运算符，然后再将当前运算符压入栈s1中
           case '+':
           case '-':
               for(ch=Top(s1);ch!='#';ch=Top(s1))
               {                
                   if(ch=='(')
                   {                        
                       break;
                   }
                   else
                   {
                       Pop(s1,ch);
                       Push(s2,ch);                        
                   }                                          
               }
               Push(s1,*p);
               length++;
               break;
           case '*':
           case '/':
               for(ch=Top(s1);ch!='#'&&ch!='+'&&ch!='-';ch=Top(s1))
               {                
                   if(ch=='(')
                   {                        
                       break;
                   }
                   else
                   {
                       Pop(s1,ch);
                       Push(s2,ch);
                   }                                          
               }
               Push(s1,*p);
               length++;
               break;
           //遇操作数则直接压入栈s2中
           default:
               Push(s2,*p);   
               length++;             
       }
    }    
    //若栈s1非空，则将栈中元素依次弹出并压入栈s2中
    while(!StackEmpty(s1)&&Top(s1)!='#')
    {
       Pop(s1,ch);
      Push(s2,ch);        
    }
    //最后将栈s2输出，逆序排列成字符串;
    char *result;
    result=(char *)malloc(sizeof(char)*(length+1));
    result+=length;
    *result='\0';
    result--;
    for(;!StackEmpty(s2);result--)
    {
       Pop(s2,ch);
       *result=ch;        
    }
   ++result;
   return result;
}
// 3-31
Status Palindrome() {
    InitStack(S1);
    InitStack(S2);
    ch = getchar();
    while (ch != '@') {
        Push(S1, ch);
        ++count;
    }
    if (count % 2 == 0) {
        for (i = 1; i <= count / 2; ++i) {
            Pop(S1, e1);
            Push(S2, e1);
        }
    }
    else {
        for (i = 1; i <= count / 2; ++i) {
            Pop(S1, e1);
            Push(S2, e1);
        }
        Pop(S1, e1);
    }
    for (i = 1; i <= count / 2; ++i) {
        Pop(S1, e1);
        Pop(S2, e2);
        if (e1 != e2) {
            return NO;
            break;
        } 
    }
    ClearStack(S1);
    ClearStack(S2);
    return OK;
}
// 3-32
Status EnQueue(SqQueue &Q, QElemType e, int k) {
    if ((Q.rear + 1) % k == Q.front)
        return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % k;
    return OK;
}
Status InitQueue(SqQueue *Q)
{
    (*Q).base = (QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
    if(!((*Q).base))
        exit(OVERFLOW);

    (*Q).rear = 0;
    (*Q).length = 0;
}
Status QueueFull(SqQueue Q)     
{
    if(Q.length==MAXQSIZE)
        return TRUE;
    else
        return FALSE;
}

int SumQueue(SqQueue Q)
{
    int i, sum;

    for(i=0,sum=0; i<Q.length; i++)
        sum += Q.base[i];

    return sum;
}

Status K_Fib(int k, int fib[], int *n)
{
    int i, sum;
    SqQueue Q;
    QElemType e;

    if(k<2 || MAX<0)
        return ERROR;

    InitQueue(&Q);

    for(i=0; i<=k-2; i++)       //前k-1项为0
        EnQueue(&Q, 0);
    EnQueue(&Q, 1);     //第k项为1

    for(i=0; i<=k-1; i++)
        fib[i] = Q.base[i];  //初始化k阶斐波那契数列
    *n = k-2;

    if(MAX>0) {
        do {
            (*n)++;              //要返回的n
            sum = SumQueue(Q);   //求第n+1项
            fib[(*n)+1] = sum;
            Q.base[Q.rear] = sum;  //更新循环数列值
            Q.rear = (Q.rear+1)%MAXQSIZE; //更新最后一项的下标
        }while(sum<=MAX);       //第n+1项小于sum
    }

    return OK;
}
// 5-17
/*
已知顺序表L含有n个整数，试分别以函数形式写出下列运算的递归运算法：
（1）求表中的最大整数；
（3）求表中n个整数之和；
*/
Status MaxNumber(GList gl, length) {
    if (length == 1) {
        return gl.elem[length - 1];
    } else {
        if (gl.elem[length - 1] > MaxNumber(gl, --length)) {
            return GList.elem[length - 1];
        } else {
            return MaxNumber(gl, --length);
        }
    }
}
 Status SumNumber(GList gl, length) {
     if (length == 1) {
         return gl.elem[length - 1];
     } else {
         return gl.elem[length - 1] + SumNumber(gl, --length);
     }
 }
// 5-19
/*
求矩阵中的所有马鞍点，并分析最坏情况下的时间复杂度。
若某个元素是第i行中的最小值，同时又是第j列中的最大值，则称其为带矩阵中的一个马鞍点。
由题意可知，矩阵中马鞍点的个数不大于1.
*/
Status SaddlePoint(Matrix md2) {
    // 先求各行的最小值， 再求各列的最大值， 相等的就是马鞍点。
    for (i = 0; i < md2.row; ++i) {
        RowMin[i] = md2[i][0];
        for (j = 1; j < md2.col; ++j) {
            if (RowMin[i] > md2[i][j]) {
                RowMin[i] = md2[i][j];
            }
        }
    }
    for (i = 0; i < md2.col; ++i) {
        ColMax[i] = md2[0][i];
        for (j = 0; j < md2.row; ++j) {
            if (ColMax[i] < md2[j][i]) {
                ColMax[i] = md2[j][i];
            }
        }
    }
    for (i = 0; i < md2.row; ++i) {
        for (j = 0; j < md2.col; ++j) {
            if (RowMin[i] == ColMax[j]) {
                printf(RowMin[i]);
                return;
            }
        }
    }
    printf("There is no saddle point.");
}
时间复杂度最大为： O（3*row*col）
// 5-30
/*
试按表头、表尾的分析方法重写求广义表深度的递归算法。
表头表尾分析法：https://wenku.baidu.com/view/d770a981ec3a87c24028c487.html、课本115页。
*/
typedef enum {ATOM,LIST} ElemTag;
typedef struct GLNode {
    ElemTag tag;
    union {
        char atom;
        struct { 
            GLNode *hp, *tp;
        } ptr;
    }un;
} *GList;

Status GListDepth(GList gl) {
    if(!gl) { // 空表
        return 1;
    }
    if(gl->tag == ATOM) { // 原子
        return 0;
    }
    m = GListDepth(gl->un.ptr.hp) + 1; // 表头深度 
    n = GListDepth(gl->un.ptr.tp); // 表尾深度
    return m > n ? m : n;
}
// 5-32
/*
试编写判别两个广义表是否相等的递归算法。
*/
Status EqualGList(GList gl1, GList gl2) {
    //判断两广义表是否是否相等，只需判断两表的子表是否相等。
    if (!gl1 && !gl2) { // 两个表都是空表
        return equal;
    } else if (!gl1 || !gl2) { // 其中一个是空的
        return not_equal;
    } else { // 两表都不为空
        if(gl1->tag == gl2->tag) { // 结点类型相同
            if(gl1->tag == Atom) { // 都是原子项
                if(gl1->union.atom != gl2->union.atom)
                    return not_equal;
            } else { // 都是子表
                EqualGList(gl1->union.ptr.hp, gl2->union.ptr.hp);
                EqualGList(gl1->union.ptr.tp, gl2->union.ptr.tp);
            }
        } else { // 结点类型不等
            return not_equal;
        }
    }
    return equal;
}
// 5-33
/*
试编写递归算法，输出广义表中所有原子项及其所在层次。
*/
Status PrintAtomAndLevel(GList gl, level/* = 0*/) {
    if (!gl) { // 空
        printf("This is a blank list. Or ended up.");
    } else {
        if (gl->tag == Atom) {
            printf(gl->union.atom, level);
        } else {
            PrintAtomAndLevel(gl->union.ptr.hp, level + 1);
            PrintAtomAndLevel(gl->union.ptr.tp, level);
        }
    }
}
// 5-37
/*
试编写递归算法，删除广义表中所有值等于x的原子项。
*/
Status DeleteValueX(GList gl, x) {
    // 删除值为X的原子结点
    if (!gl) { // 空
        /*Do nothing.*/
    } else {
        if (gl->tag == Atom) { 
            if (gl->uniom.atom == x) { // 删除该结点
                temp = gl;
                p = gl->union.ptr.tp;
                gl = p;
                free(temp);
            }
            DeleteValueX(gl, x);
        } else {
            DeleteValueX(gl->union.ptr.hp, x);
            DeleteValueX(gl->union.ptr.tp, x);
        }
    }
}
// 5-38
/*
试编写算法，依次从左至右输出广义表中第l层的原子项。
*/
Status PrintAtomAndLevel(GList gl, level/* = 0*/, l) {
    if (!gl) { // 空表
        printf("This is a blank list. Or ended up.");
    } else {
        if (gl->tag == Atom && level == l) {
            printf(gl->union.atom);
        } else {
            PrintAtomAndLevel(gl->union.ptr.hp, level + 1, l);
            PrintAtomAndLevel(gl->union.ptr.tp, level, l);
        }
    }
}
// 6-8
证明：一棵满k叉树上的叶子结点数n0和非叶子结点数n1之间满足以下关系：
n0 = （k - 1）n1 + 1

证明：
∵这是一棵满k叉树
∴设该树有m层，则共有 1-k^m / 1-k 个结点，叶子结点数 n0 = k^(m - 1)
∴非叶子结点数 n1 = 1-k^m / 1-k - k^(m - 1)
∴(k - 1)n1 + 1 = (k - 1)(1-k^m / 1-k - k^(m - 1)) + 1 = k^(m - 1) = n0
∴一棵满k叉树上的叶子结点数n0和非叶子结点数n1之间满足以下关系：n0 = （k - 1）n1 + 1
原命题得证
// 6-10
对于那些所有非叶子结点均有非空左右子树的二叉树：
(1)试问：有n个叶子结点的树中共有多少个结点？
(2)试证明：∑i=1->n 2^-(li - 1) = 1，其中n为叶子结点的个数，li表示第i个叶子结点所在的层次(设根结点所在的层次为1)

解：
(1)假设共有x个结点，∵除根节点外，每个节点都有一个分支进入，∴二叉树中的分支数为 B = x - 1，
除叶子外，共有x - n 个节点，从这样的节点出去的分支数为2， ∴B = 2(x - n)
∴B = x - 1 = 2(x - n) ∴x = 2n - 1
(2)证：数学归纳法
当n = 1时，显然成立；
假设n = p 时仍然成立，则有∑i=1->p 2^-(li - 1) = 1时，成立，假设此时有一叶子节点为m；
当n = p + 1时,此时，叶子节点数增加1，总结点数增加2.假设增加的叶子节点是原来m节点的孩子x,y之一。
∴lm + 1= lx = ly ∴2^-(lx - 1) = 2^-(ly - 1) = 2^-(lm)
∑i=1->p+1 2^-(li - 1) = 2^-(l1 - 1) + 2^-(l2 - 1) + …… + 2^-(lx - 1) + 2^-(ly - 1) + …… + 2^-(lp+1 - 1)
=2^-(l1 - 1) + 2^-(l2 - 1) + …… + 2^-(lm - 1)+ …… + 2^-(lp+1 - 1)=1
∴∑i=1->n 2^-(li - 1) = 1，其中n为叶子结点的个数，li表示第i个叶子结点所在的层次(设根结点所在的层次为1)，原命题得证
// 6-31
证明：由一棵二叉树的先序序列和中序序列可唯一确定这棵二叉树。

证：设先序序列为m1, m2, m3,,,mn,中序序列为mx1, mx2, mx3 ,,, mxn. x1, x2, x3 ,,, xn 是1， 2， 3 ，，， n
的一个排列。由先序序列知，二叉树的根节点为m1， 1对应于xx， ∴该二叉树的左子树为 mx1, mx2, mx3 ,,, mxx， 右子树为
mxx+1, mxx+2, mxx+3 ,,, mxn. 对子树 mx1, mx2, mx3 ,,, mxx 是中序序列, 子树 m1, m2, m3,,,my 为先序排列，
同理，可得该子树的根节点和左右子树。如此进行，可唯一确定该二叉树的所有子树和根节点。∴可唯一确定这棵二叉树。
// 6-36
/*
若已知两棵二叉树B1和B2皆为空，或者皆不空且B1的左、右子树和B2的左、右子树分别相似，则称二叉树B1和B2相似。
试编写算法，判别给定的两颗二叉树是否相似。
*/
Status Similar(BiTree bt1, BiTree bt2) {
    if (TreeEmpty(bt1) && TreeEmpty(bt2)) { // 两树都为空
        return OK;
    } else if (!TreeEmpty(bt1) && !TreeEmpty(bt2)) { // 两树都不为空
        if (Similar(bt1->lchild, bt2->lchild) && Similar(bt1->rchild, bt2->rchild)) {
            return OK;
        } else {
            return NO;
        }
    } else { // 一棵为空，一棵不空
        return NO;
    }
}
// 6-41
/*编写递归算法，在二叉树中求位于先序序列中第k个位置的节点的值。*/
Status ValueAtK(BiTree bt, m, k, *count, &e) { // count 计数 m 序列长度
    if (k > m ) { // k 超过序列长度了
        return ERROR;
    }
    if (bt) {
        ++(*count);
        if ((*count) == k) {
            e = bt->data;
            break;
        } else {
            ValueAtK(bt->lchild, m, k, count, e);
            ValueAtK(bt->rchild, m, k, count, e);
        }
    }
}
// 6-42
/*编写递归算法，计算二叉树中叶子节点的数目。*/
Status CountLeaves(BiTree bt, *count) { // count 计数的
    if (bt) {
        if (bt->lchild == NULL && bt->rchild == NULL) { // 叶子
            ++(*count);
        } else {
            CountLeaves(bt->lchild, count);
            CountLeaves(bt->rchild, count);
        }
    }
}
// 6-43
/*编写递归算法，将二叉树中所有节点的左右子树相互交换。*/
Status Exchange(BiTree bt) {
    if (bt) {
        // 交换 lchild rchild
        temp = bt->lchild;
        bt->lchild = bt->rchild;
        bt->rchild = temp;
        
        Exchange(bt->lchild);
        Exchange(bt->rchild);
    }
}
// 6-49
/*编写算法判别给定二叉树是否为完全二叉树。*/
int CompleteBiTree(BiTree T) {
    int i, j;
    BiTree p[100] = {};                 //树指针数组，模拟队列 
    int order[100] = {}; 
    
    i = j = 0;
    
    if(T) {                         //遍历的同时为各结点编号 
        p[j] = T;   
        order[j] = 1;
        j++;
        
        while(i<j) {
            if(i>0 && order[i]>order[i-1]+1)
                return 0;           //若结点序号不连续，则非完全二叉树 
                
            if(p[i]->lchild) {
                p[j] = p[i]->lchild;
                order[j] = 2*order[i];
                j++;            
            }

            if(p[i]->rchild) {
                p[j] = p[i]->rchild;
                order[j] = 2*order[i]+1;
                j++;
            }
            
            i++;        
        }
    }
    return 1;
}
// 6-56
/*试写一个算法，在先序后继线索二叉树中，查找给定结点*p在先序序列中的后继（假设二叉树的根结点未知）。
并讨论实现此算法对存储结构有何要求？*/
//线索二叉树的定义
typedef enum {Link,Thread} PointerTag;//Link==0指针；Thread==1线索
typedef structThrBiTree {
    TElemTypedata;
    strcatThrBiTree*lchild,*rchile;//左右指针
    PointerTagLTag,RTag;//左右标志
}ThrBiTree,*ThrBiTree;
//后继
ThrBiTree Houji(ThrBiTreep) {
    if(p->RTag==Thread)
        p=p->rchild;
    else {
        if(p->lchild!=NULL)
            p=p->lchild;
        else
            p=p->rchild;
    }
    //原p是否为最后一个结点，即现p是否是头结点
    if(p->data!=NULL)
        returnp;
    //非头结点
    else
        return NULL;//最后一个结点无后继
}
// 6-61
void degree(CSTree T,int &max) {//max初值赋值为0
    int n;
    if(T!=NULL) {
        if(T->lchild!=NULL) {
            n = 1;
            p = T->firstchild;
            while(p!=NULL) {
                p = p->nextsibling;
                n++;
            }
            if(n>max) max = n;
        }
        degree(T->firstchild,max);
        degree(T->nextsibling,max);
    }
}
// 6-62
int GetDepth CSTree(CSTree T) {
  if(!T) return0;
  else 
     for(maxd=0,p=T->firstchild;p;p=p->nextsib)
        if(d=GetDepth_ CSTre(p)>maxd) 
            maxd=d; 
     return maxd+1;
}
// 6-65
char Pred,Ind; //假 设前序序列和中序序列已经分别储存在数组Pre和In中
Bitree Build Sub(int Pre_ Start,int Pre_ End,int  In_ Start,intIn End) {//由子树的前序和中序序列建立其二叉链表
    sroot=(BTNode* )malloc(sizeof(BTNode); 
    sroot->data=Pre[Pre_ Start];
    for(i=In_ Start;In[]!=sroot- >data;i++) {
        leflen=i-In Start;
        rightlen=In_ End-i; 
        if(leftlen) {
            lroot=Build_ Sub(Pre_ Start+1,Pre_ Start+leftlen,In Start,In Start+leftlen-1);
            sroot->lchild=lroot;
        }
        if(rightlen) {
        rroot=Build Sub(Pre_ End-rightlen+1,Pre_ End,In End-rightlen+1,In_ End);
        sroot->rchild=rroot;
        } 
    return  sroot;
}

main()
{
      Build Sub(1,n,1,n); 
      ..
}
// 6-69
			   void Print BiTree(BiTree T,int i) {
    if(T->rchild) 
        Print BiTree(T->rchild,i+1);
    for(=1j<=ij++) 
        printf(" ");
    for(p=fc;c=,';p->nextsib=nc,p=nc) {
        if(!CreateCSTree_ GL ist(nc))  return  ERROR;
        p->nextsib=NULL;
        if((c=getchar)!=')') {  
            return ERROR; 
            T->firtchild=NULL;
        }
   return  OK;
   }
}
// 7-22
/**
试基于图的深度优先搜索策略写一算法，判别以邻接表方式存储的有向图中是否存在由顶点vi到顶点vj的路径(i≠j)。
注意：算法中涉及的图的基本操作必须在此存储结构上实现。
*/
bool flag; // 标志变量，默认为false
void DFS(ALGraph alg, int i, int j) { // 参考课本算法7.5
    for (int w = FirstAdjVex(alg, i); w >= 0; w = NextAdjVex(alg, i, w)) {
        if (w == j) {
            flag == true;
        }
        if (!visited[w]) {
            visited[w] = true;
            if (w == j) {
                flag = true;
            } else {
                DFS(alg, w, j);
            }
        }
    }
}
Status DFS_ALGraph_ViToVj(ALGraph alg, int i, int j) {
    if (i == j) {
        return ERROR;
    } else {
        bool visited[vexnum]; // 初始值默认为false
        visited[i] = true;
        DFS(alg, i, j); // 深度优先搜索
        if (flag) { 
            return TRUE;
        } else {
            return FALSE;
        }
    }
}
// 7-23
/**
同7.22题要求。试基于图的广度优先搜索策略写一算法。 
*/
bool flag; // 标志变量，默认为false
void BFS(ALGraph alg, int i, int j) { // 参考课本算法7.6
    InitQueue(Q);
    EnQueue(&Q, i); // 顶点i入队列
    while (!QueueEmpty(Q)) {
        DeQueue(Q, u);
        for (int w = FirstAdjVex(alg, u); w >= 0; w = NextAdjVex(alg, u, w)) {
            if (w == j) {
                flag == true;
            }
            if (!visited[w]) {
                visited[w] = true;
                if (w == j) {
                    flag = true;
                } else {
                    DFS(alg, w, j);
                }
            }
            EnQueue(&Q, w); // 顶点w入队列
        }
    }
}
Status DFS_ALGraph_ViToVj(ALGraph alg, int i, int j) {
    if (i == j) {
        return ERROR;
    } else {
        bool visited[vexnum]; // 初始值默认为false
        visited[i] = true;
        BFS(alg, i, j); // 深度优先搜索
        if (flag) { 
            return TRUE;
        } else {
            return FALSE;
        }
    }
}
// 7-27
/**
采用邻接表存储结构，编写一个判别无向图中任意给定的两个顶点之间是否存在一条长度为k的简单路径的算法
（一条路径为简单路径指的是其顶点序列中不含有重现的顶点)。
*/
bool flag; // 默认值为false
bool visited[vexnum]; // 默认值为false
Stack pathStack; // 存放路径
void DFS(ALGraph alg, int i, int j, int k) {
    visited[i] = true;
    PushStack(&pathStack, i);
    if (i == j) {
        for (p = pathStack.base, count = -1; p < pathStack.top; ++p, ++count) {
            /*Do Nothing!*/
        }
        if (count == k) {
            flag = true;
        } else {
            PopStack(&pathStack, &e);
            visited[i] = false;
        }
        return;
    }
    for (int w = FirstAdjVex(alg, i); w >= 0 && !flag; w = NextAdjVex(alg, i, w)) {
        if (!visited[w]) {
            DFS(alg, w, j, k);
        }
    }
    if (!w && !flag) {
        PopStack(&pathStack, &e);
    }
}
Status FindSimplePathLenK(ALGraph alg, int i, int j, int k) {
    DFS(alg, i, j, k);
    return flag;
}
// 7-34
/**
试编写一个算法，给有向无环图G中每个顶点赋以一个整数序号，并满足以下条件：若从顶点i至顶点j有一条弧，则应使i<j。
*/
// 参考课本P182算法7.12
// P163邻接表法的定义

void FindInDegree(ALGraph G, int indegree[MAX_VERTEX_NUM])
{
    ArcNode *p；
    for (int i = 0; i < G.vexnum; ++i)
    {
        indegree[i] = 0;
    }
    for (int i = 0; i < G.vexnum; ++i)
    {
        p = G.vertices[i].firstarc;
        while (p)
        {
            ++indegree[p->adjvex];//adjvex:该弧所指向的顶点的位置
            p = p->nextarc;
        } 
    }
}

Status TopologicalSort(ALGraph G, int topo[]) //数组存储拓扑序列,邻接表法
{
    SqStack S;
    ArcNode *p;
    int k, count, indegree[MAX_VERTEX_NUM];

    FindInDegree(G, indegree); //求各个顶点的入度indegree[0, ... , vexnum - 1]
    InitStack(S);
    for (int i = 0; i < G.vexnum; ++i)//建零入度顶点栈S
    {
        if (!indegree[i])
        {
            Push(S, i);
        }
    }
    count = 0;
    while (!StackEmpty(S))
    {
        Pop(S, i);
        ++count;
        Topo[count] = i;
        for (p = G.vertices[i].firstarc; p; p = p->nextarc)
        {
            k = p->adjvex;//对i号顶点的每个邻接点入度减1
            if (!(--indegree[k]))
            {
                Push(S, k);
            }
        }
    }
    if (count < G.vexnum)
    {
        return ERROR;
    }
    else
    {
        return OK;
    }
}
// 7-42
/*
以邻接表作存储结构实现求从源点到其余各顶点的最短路径的Dijkstra算法。
*/
int GetMinumLen(ALGraph G, int i, int j)//求从i到j的最短路径长度
{
    ArcNode *p;
    p = G.vertices[i].firstarc;
    while (p && p->adjvex != j)//adjvex该弧所指向的顶点的位置
    {
        p = p->nextarc;
    }
    if (p && p->adjvex == j)
    {
        return p->info.in;
    }
    return MAX;
}
//参考课本P189算法7.15
void Dijkstra(ALGraph G, int v0, int path[], int dist[])
{
    //v0: 起始点
    //path[]: 保存从v0到路径上vi的前一个顶点
    //dist[]: 保存从v0到任一点的最短路径长度
    int set[MAX_VERTEX_NUM];//标记各顶点是否已加入路径
    int v, min, tmp[MAX_VERTEX_NUM], k;

    //初始化
    for (int i = 0; i < G.vexnum; ++i)
    {
        dist[i] = GetMinumLen(G, v0, i);
        set[i] = 0;
        if (GetMinumLen(G, v0, i) < MAX)
        {
            path[i] = v0;
        }
        else
        {
            path[i] = -1;//不通或自身
        }
    }
    set[v0] = 1;
    path[v0] = -1;

    for (int i = 0; i < G.vexnum; ++i)
    {
        min = MAX;
        for (int j = 0; j < G.vexnum; ++j)//选出v0到剩余顶点中最短的一条路径
        {
            if (!set[j] && dist[j] < min) 
            {
                v = j;
                min = dist[j];//v0到剩余顶点的最短路径<v0, v>
            }
        }
        set[v] = 1;//将顶点v加入最短路径
        for (int j = 0; j < G.vexnum; ++j)//判断v的加入是否会造成v0到剩余顶点的更短路径
        {
            if (!set[j] && min < MAX && GetMinumLen(G, v, j) < MAX && (min + GetMinumLen(G, v, j) < dist[j]))
            {
                dist[j] = min + GetMinumLen(G, v, j);
                path[j] = v;
            }
        }
    }

    for (int i = 0; i < G.vexnum; ++i)
    {
        if (v0 != i)
        {
            printf("%c 到 %c 的路径为：", G.vertices[v0].data, G.vertices[i].data);
            if (path[i] == -1)
            {
                printf("X");
            }
            else
            {
                tmp[0] = 0;//计数路径上顶点个数
                if (v0 != i)
                {
                    k = i;
                    do
                    {
                        ++tmp[0];
                        tmp[tmp[0]] = k;
                        k = path[k];
                    } while (path[k] != -1);
                }
                printf("%c ", G.vertices[v0].data);
                if (tmp[0])
                {
                    for (int j = tmp[0]; j >= 1; --j)
                    {
                        printf("%c ", G.vertices[tmp[j]].data);
                    }
                }
            }
            printf("权长为：");
            if (dist[i] == MAX)
            {
                printf("∞");
            }
            else
            {
                printf("%2d\n", dist[i]);
            }
        }
    }
}
// 9-31
/*
试写一个判别给定二叉树是否为二叉排序树的算法，设此二叉树以二叉链表作存储结构。且树中结点的关键字均不同。
*/
//判断给定二叉树是否为二叉排序树，只需验证其左子树值是否小于根节点，根节点是否小于右子树。
Status IsBSTree(BSTree T, bool flag, int *pre)
{
    if (!flag)
    {
        if (T->lchild)//左子树
        {
            IsBSTree(T->lchild, flag, pre);
        }
        if (T->data.key >= *pre)//根节点
        {
            *pre = T->data.key;
        }
        else
        {
            flag = !flag;
        }
        if (T->rchild)//右子树
        {
            IsBSTree(T->rchild, flag, pre);
        }
    }
}
// 9-33
/*
编写递归算法，从大到小输出给定二叉排序树中所有关键字不小于x的数据元素。要求你的算法的时间复杂度为O(log2n+m)，其中n为排序树中所含结点数，m为输出的关键字个数。
*/
void Print(BSTree T, int x)
{
    if (T)
    {
        Print(T->rchild, x);//右子树
        if (T->data.key >= x)//根节点
        {
            printf("%d", T->data.key);
        }
        else
        {
            return;
        }
        Print(t->lchild, x);//左子树
    }
}
// 9-35
/*
假设二叉排序树以后继线索链表作存储结构，编写输出该二叉排序树中所有大于a且小于b的关键字的算法。 
*/
void Print(BSTree T, int a, int b)
{
    BSTree *p = T->lchild;
    while (p != T)
    {
        while (p->lchild)
        {
            p = p->lchild;
        }
        if (p->data.key && p->data.key < b)
        {
            printf("%d", T->data.key);
        }
        else
        {
            if (p->data.key >= b)
            {
                return;
            }
        }

        while (p->RTag == Thread && p->rchild != T)
        {
            p = p->rchild;
            if (a < p->data.key && p->data.key < b)
            {
                printf("%d", T->data.key);
            }
            else
            {
                if (p->data.key >= b)
                {
                    return;
                }
            }
        }

        p = p->rchild;
    }
}
// 9-38
/*
试写一算法，将两棵二叉排序树合并为一棵二叉排序树。
*/
void Merge(BSTree T1, BSTree *T2)
{
    BSTree lt, rt;
    if (*T2)
    {
        lt = (*T2)->lchild;
        rt = (*T2)->rchild;
        (*T2)->lchild = (*T2)->lchild = NULL;
        Merge(T1, &lt);
        InsertNode(&T1, *T2);//课本P228算法9.5
        Merge(T1, &rt);
    }
}
