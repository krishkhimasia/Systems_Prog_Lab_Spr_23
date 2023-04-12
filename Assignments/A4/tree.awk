#!/usr/bin/gawk -f

function prntree()
{
    print "Going to read tree with",n,"nodes\n"
    for(k=1;k<=n;k++)
    {
        printf("\t%10s :  ID = %3d       Left child = %-10s       Right child = %-10s\n",K[k], k, K[L[k]], K[R[k]]);
    }
}

function findroot()
{
    for(k=1;k<=n;k++)
    {
        if(!P[k])
        {
            print "The root node has ID",k,"and key \""K[k]"\"";
            return k
        }
    }
}

function inorder(id)
{
    if(!(id<=n && id>=1))               #if id is not a valid node ID, return
    {
        return
    }
    inorder(L[id])                      #inorder traversal of left subtree
    if(count%5==0){
        printf("\n")
    }
    printf("\t%10s",K[id],count,id)     #print the key
    count++
    inorder(R[id])                      #inorder traversal of right subtree
}

BEGIN{
    FS=":"
    i=1
}

# reading input and populating the arrays
{
    if(NR==1)
    {
        n=$1;       #first record contains number of nodes
    }
    else
    {
        if(!H[$1])      #populating H and K as per definition
        {
            H[$1]=i;
            K[i]=$1
            i++
        }
        split($2,children,",")
        for(j in children)
        {
            if(!H[children[j]] && children[j]!="")
            {
                H[children[j]]=i;
                K[i]=children[j]
                i++
            }
        }
        if(children[1]){
            L[H[$1]]=H[children[1]]
            P[H[children[1]]]=H[$1]
        }
        if(children[2]){
            R[H[$1]]=H[children[2]]
            P[H[children[2]]]=H[$1]
        }
        for(j in children){
            if(!L[H[children[j]]]){
                L[H[children[j]]]=0         #no left child => L[id]=0
            }
            if(!R[H[children[j]]]){
                R[H[children[j]]]=0         #no right child => R[id]=0
            }
        }
        H["-"]=0
        K[0]="-"
    }
}

END{
    prntree()
    print "\n"
    rootID=findroot()
    print "\n"
    count=0;
    print "Inorder listing of the keys:"
    inorder(rootID)
    printf("\n\n")
    print "Bye..."
}