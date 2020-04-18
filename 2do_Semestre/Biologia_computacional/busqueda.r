library(RISmed)
search_query <- EUtilsSummary(query_colon)
search <-EutilsSummary("((hepatitis[Ti]) AND virus[Ti]) AND child[Ti] ")
print(summary(search))