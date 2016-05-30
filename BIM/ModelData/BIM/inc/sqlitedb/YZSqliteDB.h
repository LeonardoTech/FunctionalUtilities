#ifndef __YZSQLITDB_H__
#define __YZSQLITDB_H__

#ifdef _WIN32
#ifdef SQLITEDB_EXPORTS
#define SQLITE_API __declspec(dllexport)
#else
#define SQLITE_API __declspec(dllimport)
#endif
#else
#define SQLITE_API
#endif

#include "YZPrerequire.h"

namespace YZ
{
	class DBOperation;

	class SQLITE_API SqliteDB
	{
	public:
		SqliteDB(void);

		virtual ~SqliteDB(void);

		//创建Sqliet数据库链接
		//strDBName Sqliet数据库文件的全路径
		bool ConnectDB(const std::string& dbpath);

		//关闭数据库
		bool CloseDB(void);

		/*
		非查询操作（插入，更新，删除，创建）
		*/
		//提交执行除查询(select...)之外的其它SQL语句
		bool ExecuteNonQuery(const char* sql);

		bool BeginExecute(const char* sql);
		void FinishExecute(void);

		//插入操作，
		bool SetInsertData(int index, const char* value);
		bool SetInsertData(int index, int value);
		bool SetInsertData(int index, const char* value, int size);
		bool InsertData(void);

		/*
		查询操作
		取得指定条件的数据，strSQl: (Select...From...Where...)SQL语句
		*/
		//通过ExecuteQueryVectorData进行查询操作，查询结果集从GetQueriedVectorData接口返回
		//返回双层嵌套vector的结果，内层vector为字段的索引，外层vector为行的索引
		//注意：vector内容是结果集数据的指针，对应的数据存贮在相应的堆上，读取完
		//vector的内容需要手动释放每个成员对应的空间(delete [] vector[i][j];)
		bool ExecuteQueryVectorData(const char* sql);
		std::vector<std::vector<char*> >& GetQueriedVectorData(void);

		//同Vector
		bool ExecuteQueryListData(const char* sql);
		std::list<std::vector<char*> >& GetQueriedListData(void);

		//通过ExecuteQuery进行查询操作，查询结果集通过后续的接口获取
		//GetQueriedDataCount获取数据数目，QueryData获取下一条数据，为false说明数据取完或者读取出错
		//GetQueriedData获取每列的一个数据
		//数据获取完毕通过CloseQuery关闭查询状态
		//这种获取数据的方式主要是为了兼容二进制数据的获取
		int GetQueriedCount(void);

		bool SetSelectParameter(int index, const char* value);
		bool SetSelectParameter(int index, int value);
		bool SelectParameter(void);

		bool QueryData(void);
		bool GetQueriedData(int column, char*& value);
		bool GetQueriedData(int column, int& value);
		bool GetQueriedData(int column, char*& value, int& size);

		/*
		事务操作
		*/
		//开始执行数据库事物
		//返回值为sqlite处理ID，成功为0，其它表示失败
		bool BeginTransaction();

		//提交数据库事物
		//返回值为sqlite处理ID，成功为0，其它表示失败
		bool CommitTransaction();

		//回滚数据库事物
		//返回值为sqlite处理ID，成功为0，其它表示失败
		bool RollbackTransaction();

		//释放数据库占用的内存
		//返回已经释放的内存字节
		bool FreeDBMemory();

	protected:
		//断开Sqliet数据库链接，析构时会自动调用此接口
		void DisconnectDB(void);

	protected:
		DBOperation* m_operation;
	};
}

#endif