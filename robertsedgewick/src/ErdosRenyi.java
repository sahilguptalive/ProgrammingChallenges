import java.util.Random;
import java.lang.System;


public class ErdosRenyi{

    private static enum Algo{
        QUICK_FIND,
        QUICK_UNION,
        QUICK_UNION_WEIGHTED_SIZE,
        QUICK_UNION_WEIGHTED_HEIGHT,
        QUICK_UNION_WEIGHTED_SIZE_PATH_COMPRESSION,
        QUICK_UNION_WEIGHTED_HEIGHT_PATH_COMPRESSION
    }

    public static void main(String[] args) {
        if(args==null||args.length<2){
            throw new IllegalArgumentException("args needs to be passed");
        }
        int N1=Integer.parseInt(args[0]);
        int T=Integer.parseInt(args[1]);
        double lastTime=0;
        Algo algo=Algo.QUICK_UNION_WEIGHTED_SIZE_PATH_COMPRESSION;
        for(int N=N1;N<N1*100000;N*=2){ 
            double avgConnections=0;
            double avgTimeTaken=0;
            for(int t=0;t<T;t++){ 
                long startTime=System.currentTimeMillis();
                avgConnections+=((double)count(algo,N)/T);
                long endTime=System.currentTimeMillis();
                avgTimeTaken+=((double)(endTime-startTime)/T);
            }
            System.out.println("Algo: "+algo+" N: "+N+" connections: "+avgConnections
                    +" time:"+(avgTimeTaken)
                    +" 2^b:"+(lastTime==0?1:(avgTimeTaken/lastTime)));
            lastTime=avgTimeTaken;
        }
    }
    public static int count(Algo algo,int N){
        int[] id=new int[N];
        int[] size=new int[N];
        Random random=new Random();
        int edges=0;
        int count=N;
        initId(id,N);
        initSize(size,N);
        while(count>1){
            int p=random.nextInt(N);
            int q=random.nextInt(N);
            if(union(algo,id,size,p,q)){
                count--;
            }
            edges++;
        }
        return edges;
    }

    private static void initId(int[] id,int N){
        for(int i=0;i<N;i++){
            id[i]=i;
        }
    }
    private static void initSize(int[] size,int N){
        for(int i=0;i<N;i++){
            size[i]=1;
        }
    }

    private static int find(final int[] id,int p){
        int par=id[p];
        while(par!=p){
            p=par;
            par=id[p];
        }
        return p;
    }

    private static boolean connected(int[] id,int p,int q){
        return find(id,p)==find(id,q);
    }

    private static boolean union(Algo algo,int[] id,int size[],int p,int q){
        switch(algo){
            case QUICK_FIND:
                return quickFind(id,size,p,q);
            case QUICK_UNION:
                return quickUnion(id,size,p,q);
            case QUICK_UNION_WEIGHTED_SIZE:
                return quickUnionWeightedSize(id,size,p,q);
            case QUICK_UNION_WEIGHTED_HEIGHT:
                return quickUnionWeightedHeight(id,size,p,q);
            case QUICK_UNION_WEIGHTED_SIZE_PATH_COMPRESSION:
                return quickUnionWeightedSizePathCompression(id,size,p,q);
            case QUICK_UNION_WEIGHTED_HEIGHT_PATH_COMPRESSION:
                return quickUnionWeightedHeightPathCompression(id,size,p,q);
            default:
                throw new IllegalArgumentException("specified algo not implemented yet");
        }
    }

    private static boolean quickFind(int[] id,int size[],int p,int q){
        int rootP=find(id,p);
        int rootQ=find(id,q);
        if(rootP==rootQ){
            return false;
        }
        for(int i=0;i<id.length;i++){
            if(id[i]==rootQ){
                id[i]=rootP;
            }
        }
        return true;
    }
    private static boolean quickUnion(int[] id,int size[],int p,int q){
        int rootP=find(id,p);
        int rootQ=find(id,q);
        if(rootP==rootQ){
            return false;
        }
        id[rootQ]=rootP;
        return true;
    }
    private static boolean quickUnionWeightedSize(int[] id,int size[],int p,int q){
        int rootP=find(id,p);
        int rootQ=find(id,q);
        if(rootP==rootQ){
            return false;
        }
        if(size[rootP]<size[rootQ]){
            id[rootP]=rootQ;
            size[rootQ]+=size[rootP];
        }else{
            id[rootQ]=rootP;
            size[rootP]+=size[rootQ];
        }
        return true;
    }
    private static boolean quickUnionWeightedHeight(int[] id,int size[],int p,int q){
        int rootP=find(id,p);
        int rootQ=find(id,q);
        if(rootP==rootQ){
            return false;
        }
        if(size[rootP]<size[rootQ]){
            id[rootP]=rootQ;
        }else{
            id[rootQ]=rootP;
            size[rootP]+=(size[rootP]==size[rootQ]?1:0);
        }
        return true;
    }
    private static boolean quickUnionWeightedHeightPathCompression(int[] id,int size[],int p,int q){
        int rootP=find(id,p);
        int rootQ=find(id,q);
        if(rootP==rootQ){
            return false;
        }
        if(size[rootP]<size[rootQ]){
            id[rootP]=rootQ;
            compress(id,rootQ,rootQ,p);
            compress(id,rootQ,rootQ,q);
        }else{
            id[rootQ]=rootP;
            compress(id,rootP,rootP,p);
            compress(id,rootP,rootP,q);
            size[rootP]+=(size[rootP]==size[rootQ]?1:0);
        }
        return true;
    }
    private static boolean quickUnionWeightedSizePathCompression(int[] id,int size[],int p,int q){
        int rootP=find(id,p);
        int rootQ=find(id,q);
        if(rootP==rootQ){
            return false;
        }
        if(size[rootP]<size[rootQ]){
            id[rootP]=rootQ;
            size[rootQ]+=size[rootP];
            compress(id,rootQ,rootQ,p);
            compress(id,rootQ,rootQ,q);
        }else{
            id[rootQ]=rootP;
            size[rootP]+=size[rootQ];
            compress(id,rootP,rootP,p);
            compress(id,rootP,rootP,q);
        }
        return true;
    }
    private static void compress(int[] id,int oldRoot,int newRoot,int leaf){
        int par=leaf;
        do{
            par=id[leaf];
            id[leaf]=newRoot;
            leaf=par;
        }while(leaf!=oldRoot);
        id[oldRoot]=newRoot;
    }
}
