  import { Navbar } from '@/components/Navbar';
  import { ResourceTypeCard } from '@/components/ResourceTypeCard';
  import { ResourceItem } from '@/components/ResourceItem';
  import { Empty } from '@/components/Empty';
  import { useResourceContext } from '@/contexts/resourceContext.tsx';
  import { useState, useEffect } from 'react';
  import { getResourcesByTypeId } from '@/mocks/resources';
  import { Resource } from '@/types';
  
  export default function Home() {
    const { resourceTypes } = useResourceContext();
    const [searchTerm, setSearchTerm] = useState('');
    const [searchResults, setSearchResults] = useState<Resource[]>([]);
    const [showResults, setShowResults] = useState(false);
  
    // 搜索功能实现
    useEffect(() => {
      const delayDebounceFn = setTimeout(() => {
        if (searchTerm.trim().length > 0) {
          // 获取所有资源
          const allResources: Resource[] = [];
          resourceTypes.forEach(type => {
            const resources = getResourcesByTypeId(type.id);
            allResources.push(...resources);
          });
          
          // 搜索过滤
          const results = allResources.filter(resource => 
            resource.title.toLowerCase().includes(searchTerm.toLowerCase()) ||
            resource.content.toLowerCase().includes(searchTerm.toLowerCase()) ||
            (resource.tags && resource.tags.some(tag => 
              tag.toLowerCase().includes(searchTerm.toLowerCase())
            ))
          );
          
          setSearchResults(results);
          setShowResults(true);
        } else {
          setShowResults(false);
        }
      }, 300); // 300ms防抖
      
      return () => clearTimeout(delayDebounceFn);
    }, [searchTerm, resourceTypes]);
  
    return (
      <div className="min-h-screen bg-gray-50 dark:bg-gray-900">
        <Navbar />
        
        <main className="max-w-7xl mx-auto py-6 px-4 sm:px-6 lg:px-8">
          {/* 搜索框 */}
          <div className="mb-8">
              <div className="relative max-w-2xl mx-auto">
                <input
                  type="text"
                  placeholder="搜索资源..."
                  value={searchTerm}
                  onChange={(e) => setSearchTerm(e.target.value)}
                  className="w-full pl-10 pr-4 py-3 rounded-lg border border-gray-200 dark:border-gray-700 bg-white dark:bg-gray-800 shadow-sm focus:outline-none focus:ring-2 focus:ring-primary/50 dark:text-white transition-all duration-300 focus:border-primary focus:shadow-md"
                />
                <i className="fa-solid fa-search absolute left-3 top-1/2 transform -translate-y-1/2 text-gray-400 transition-colors duration-300 focus-within:text-primary"></i>
                {searchTerm && (
                  <button 
                    onClick={() => setSearchTerm('')}
                    className="absolute right-3 top-1/2 transform -translate-y-1/2 text-gray-400 hover:text-error dark:hover:text-error transition-all duration-300 hover:scale-110"
                  >
                    <i class="fa-solid fa-times-circle"></i>
                  </button>
                )}
                <div className="absolute -bottom-1 left-0 right-0 h-0.5 bg-gradient-to-r from-transparent via-primary to-transparent transform scale-x-0 transition-transform duration-300 origin-left focus-within:scale-x-100"></div>
              </div>
          </div>
          
          {/* 搜索结果展示 */}
          {showResults ? (
            <div className="mb-10">
              <h2 className="text-2xl font-bold text-gray-900 dark:text-white mb-4 flex items-center">
                <i className="fa-solid fa-search mr-2 text-blue-500"></i>
                搜索结果: {searchResults.length} 个资源
              </h2>
              
              {searchResults.length === 0 ? (
                <div className="text-center py-12 bg-white dark:bg-gray-800 rounded-lg border border-gray-200 dark:border-gray-700">
                  <i className="fa-solid fa-file-search text-4xl text-gray-300 dark:text-gray-600 mb-3"></i>
                  <p className="text-gray-500 dark:text-gray-400">未找到与"{searchTerm}"相关的资源</p>
                </div>
              ) : (
                <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
                  {searchResults.map(resource => (
                    <ResourceItem key={resource.id} resource={resource} />
                  ))}
                </div>
              )}
            </div>
          ) : (
            <div className="mb-8">
              <h1 className="text-3xl font-bold text-gray-900 dark:text-white">资源分类</h1>
              <p className="mt-1 text-gray-600 dark:text-gray-400">
                选择以下分类查看相关资源
              </p>
            </div>
          )}
 
         {resourceTypes.length === 0 ? (
           <div className="text-center py-12">
             <Empty />
             <p className="mt-2 text-gray-500 dark:text-gray-400">暂无资源分类，请先添加分类</p>
           </div>
         ) : (
           <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 gap-6">
              {resourceTypes.map((type) => (
                <ResourceTypeCard 
                  key={type.id} 
                  type={type} 
                />
              ))}
           </div>
         )}
       </main>
     </div>
   );
 }