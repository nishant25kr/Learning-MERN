import { useEffect, useState } from "react";

function App() {
  const [query, setQuery] = useState("");
  const [debouncedQuery, setDebouncedQuery] = useState("");
  const [finalSearch,setFinalSearch] = useState("")

  useEffect(() => {
    const timer = setTimeout(() => {
      setDebouncedQuery(query);
    }, 500);

    return () => clearTimeout(timer);
  }, [query]);

  useEffect(() => {
    if (debouncedQuery) {
      // search(debouncedQuery);
      setFinalSearch(debouncedQuery)
    }
  }, [debouncedQuery]);

  return (
    <>
      <input
        value={query}
        onChange={(e) => setQuery(e.target.value)}
        placeholder="Search..."
      />
      <div>
        searching = {query}
      </div>

      <div>
        final search = {finalSearch}
      </div>
    </>
  );
}

export default App
