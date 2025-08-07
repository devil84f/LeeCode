import { useEffect, useState } from 'react';
import { useParams, useNavigate, Link } from 'react-router-dom';
import { Navbar } from '@/components/Navbar';
  import { useResourceContext } from '@/contexts/resourceContext.tsx';
  import { Empty } from '@/components/Empty';
  import { toast } from 'sonner';
  import { Resource } from '@/types';

export default function ResourceDetail() {
  const { id } = useParams<{ id: string }>();
  const navigate = useNavigate();
  const { getResourceById, deleteResource, resourceTypes } = useResourceContext();
  const [resource, setResource] = useState<Resource | null>(null);
  const [loading, setLoading] = useState(true);
  const [typeName, setTypeName] = useState('');
  
  useEffect(() => {
    if (!id) {
      navigate('/');
      return;
    }
    
    const resourceData = getResourceById(id);
    if (!resourceData) {
      toast.error('资源不存在或已被删除');
      navigate('/');
      return;
    }
    
    setResource(resourceData);
    
    // 获取类型名称
    const type = resourceTypes.find(t => t.id === resourceData.typeId);
    setTypeName(type?.name || '未知分类');
    
    setLoading(false);
  }, [id, navigate, getResourceById, resourceTypes]);
  
  const handleDelete = () => {
    if (resource && confirm(`确定要删除资源"${resource.title}"吗？`)) {
      deleteResource(resource.id);
      toast.success('资源已删除');
      navigate(`/resources/${resource.typeId}`);
    }
  };
  
  if (loading) {
    return (
      <div className="min-h-screen bg-gray-50 dark:bg-gray-900 flex items-center justify-center">
        <div className="text-center">
          <i class="fa-solid fa-spinner fa-spin text-3xl text-blue-600 mb-2"></i>
          <p>加载中...</p>
        </div>
      </div>
    );
  }
  
  if (!resource) {
    return (
      <div className="min-h-screen bg-gray-50 dark:bg-gray-900 flex items-center justify-center">
        <Empty />
      </div>
    );
  }
  
  return (
    <div className="min-h-screen bg-gray-50 dark:bg-gray-900">
      <Navbar />
      
      <main className="max-w-3xl mx-auto py-6 px-4 sm:px-6 lg:px-8">
        <div className="bg-white dark:bg-gray-800 rounded-lg shadow overflow-hidden border border-gray-200 dark:border-gray-700">
          <div className="p-6">
            <div className="flex flex-wrap items-center justify-between gap-4 mb-4">
              <span className="inline-flex items-center px-2.5 py-0.5 rounded-full text-xs font-medium bg-blue-100 text-blue-800 dark:bg-blue-900 dark:text-blue-300">
                {typeName}
              </span>
              
              <div className="flex space-x-2">
                <Link
                  to={`/resource/edit/${resource.id}`}
                  className="inline-flex items-center px-3 py-1 border border-gray-300 dark:border-gray-600 rounded-md text-sm font-medium text-gray-700 dark:text-gray-300 bg-white dark:bg-gray-800 hover:bg-gray-50 dark:hover:bg-gray-700"
                >
                  <i class="fa-solid fa-edit mr-1"></i> 编辑
                </Link>
                
                <button
                  onClick={handleDelete}
                  className="inline-flex items-center px-3 py-1 border border-red-300 dark:border-red-600 rounded-md text-sm font-medium text-red-700 dark:text-red-300 bg-white dark:bg-gray-800 hover:bg-red-50 dark:hover:bg-red-900/20"
                >
                  <i class="fa-solid fa-trash mr-1"></i> 删除
                </button>
              </div>
            </div>
            
            <h1 className="text-2xl font-bold text-gray-900 dark:text-white mb-4">
              {resource.title}
            </h1>
            
            <div className="flex flex-wrap items-center text-sm text-gray-500 dark:text-gray-400 mb-6 gap-x-6 gap-y-2">
              <div className="flex items-center">
                <i class="fa-solid fa-user mr-1"></i>
                <span>作者: {resource.author}</span>
              </div>
              
              <div className="flex items-center">
                <i class="fa-solid fa-calendar mr-1"></i>
                <span>创建时间: {new Date(resource.createdAt).toLocaleString()}</span>
              </div>
              
              {resource.updatedAt !== resource.createdAt && (
                <div className="flex items-center">
                  <i class="fa-solid fa-history mr-1"></i>
                  <span>更新时间: {new Date(resource.updatedAt).toLocaleString()}</span>
                </div>
              )}
            </div>
            
            {resource.tags && resource.tags.length > 0 && (
              <div className="flex flex-wrap gap-2 mb-6">
                {resource.tags.map((tag, index) => (
                  <span 
                    key={index} 
                    className="inline-flex items-center px-2 py-0.5 rounded text-xs bg-gray-100 text-gray-800 dark:bg-gray-700 dark:text-gray-200"
                  >
                    <i class="fa-solid fa-tag mr-1 text-xs"></i> {tag}
                  </span>
                ))}
              </div>
            )}
            
            <div className="prose dark:prose-invert max-w-none">
              <h2>资源内容</h2>
              <div className="whitespace-pre-line text-gray-700 dark:text-gray-300 leading-relaxed">
                {resource.content}
              </div>
            </div>
            
            {resource.fileUrl && (
              <div className="mt-8 pt-6 border-t border-gray-200 dark:border-gray-700">
                <h3 className="text-lg font-medium text-gray-900 dark:text-white mb-3">相关文件</h3>
                <a
                  href={resource.fileUrl}
                  target="_blank"
                  rel="noopener noreferrer"
                  className="inline-flex items-center px-4 py-2 border border-transparent rounded-md shadow-sm text-sm font-medium text-white bg-blue-600 hover:bg-blue-700"
                >
                  <i class="fa-solid fa-download mr-2"></i> 下载文件
                </a>
              </div>
            )}
          </div>
        </div>
        
        <div className="mt-6 flex justify-between">
          <Link
            to={`/resources/${resource.typeId}`}
            className="inline-flex items-center text-sm text-blue-600 dark:text-blue-400 hover:text-blue-800 dark:hover:text-blue-300"
          >
            <i class="fa-solid fa-arrow-left mr-1"></i> 返回列表
          </Link>
          
          <Link
            to="/resource/upload"
            state={{ typeId: resource.typeId }}
            className="inline-flex items-center text-sm text-blue-600 dark:text-blue-400 hover:text-blue-800 dark:hover:text-blue-300"
          >
            上传相似资源 <i class="fa-solid fa-arrow-right ml-1"></i>
          </Link>
        </div>
      </main>
    </div>
  );
}