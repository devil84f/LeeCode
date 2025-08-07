 import { useEffect, useState } from 'react';
 import { useParams, Link, useNavigate } from 'react-router-dom';
 import { Navbar } from '@/components/Navbar';
 import { ResourceItem } from '@/components/ResourceItem';
 import { Empty } from '@/components/Empty';
 import { useResourceContext } from '@/contexts/resourceContext.tsx';
 import { Resource } from '@/types';
 
 export default function ResourceList() {
   const { typeId } = useParams<{ typeId: string }>();
   const navigate = useNavigate();
   const { resources: allResources, deleteResource, resourceTypes } = useResourceContext();
   const [resources, setResources] = useState<Resource[]>([]);
   const [typeName, setTypeName] = useState('');
   
   useEffect(() => {
     if (!typeId) {
       navigate('/');
       return;
     }
     
     // 从所有资源中筛选当前类型的资源
     const typeResources = allResources.filter(resource => String(resource.typeId) === String(typeId));
     setResources(typeResources);
     
     // 获取类型名称
     const type = resourceTypes.find(t => t.id === typeId);
     setTypeName(type?.name || '未知分类');
   }, [typeId, navigate, resourceTypes, allResources]);
   
  return (
    <div className="min-h-screen bg-gray-50 dark:bg-gray-900">
      <Navbar />
      
      <main className="max-w-7xl mx-auto py-6 px-4 sm:px-6 lg:px-8">
        <div className="mb-6 flex items-center justify-between">
          <div>
            <h1 className="text-2xl font-bold text-gray-900 dark:text-white">{typeName}</h1>
            <p className="mt-1 text-gray-600 dark:text-gray-400">
              共 {resources.length} 个资源
            </p>
          </div>
          
          <Link 
            to="/resource/upload" 
            state={{ typeId }}
            className="px-3 py-2 rounded-md text-sm font-medium bg-blue-600 text-white hover:bg-blue-700"
          >
            <i class="fa-solid fa-plus mr-1"></i>添加资源
          </Link>
        </div>
        
        <div className="bg-white dark:bg-gray-800 rounded-lg shadow overflow-hidden border border-gray-200 dark:border-gray-700">
          {resources.length === 0 ? (
            <div className="py-20 text-center">
              <Empty />
              <p className="mt-2 text-gray-500 dark:text-gray-400">该分类下暂无资源</p>
            </div>
          ) : (
            <div className="divide-y divide-gray-200 dark:divide-gray-700">
              {resources.map((resource) => (
                <ResourceItem 
                  key={resource.id} 
                  resource={resource} 
                  onDelete={deleteResource}
                  onEdit={(id) => navigate(`/resource/edit/${id}`)}
                />
              ))}
            </div>
          )}
        </div>
        
        <div className="mt-4">
          <Link 
            to="/" 
            className="inline-flex items-center text-sm text-blue-600 dark:text-blue-400 hover:text-blue-800 dark:hover:text-blue-300"
          >
            <i class="fa-solid fa-arrow-left mr-1"></i> 返回分类列表
          </Link>
        </div>
      </main>
    </div>
  );
}