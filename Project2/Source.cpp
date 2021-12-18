#include <string>
#include <sqlite_orm/sqlite_orm.h>

struct TestStruct
{
	int id;
	std::string test;
};

inline auto initStorage(const std::string& path)
{
	return sqlite_orm::make_storage(path,
		sqlite_orm::make_table("classes",
			sqlite_orm::make_column("id", &TestStruct::id, sqlite_orm::autoincrement(), sqlite_orm::primary_key()),
			sqlite_orm::make_column("test", &TestStruct::test)
		)
	);
};

using sqliteStorage = decltype(initStorage(""));

int main()
{
	auto storage = initStorage("fileName.sqlite");
	storage.sync_schema();

	//for (auto& item : m_storage->iterate<TestStruct>())
	//	addTestStruct(item);
}