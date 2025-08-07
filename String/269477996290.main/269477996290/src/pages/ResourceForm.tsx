import { useState, useEffect } from 'react';
import { useNavigate, useParams, useLocation } from 'react-router-dom';
import { Navbar } from '@/components/Navbar';
import { useResourceContext } from '@/contexts/resourceContext.tsx';
import { toast } from 'sonner';
import { getResourceById } from '@/mocks/resources';

interface ResourceFormData {
  title: string;
  typeId: string;
  content: string;
  author: string;
  tags: string;
  fileUrl?: string;
}

export default function ResourceForm() {
  const { id } = useParams<{ id?: string }>();
  const location = useLocation();
  const navigate = useNavigate();
  const { resourceTypes, addResource, updateResource } = useResourceContext();
  
  // 从URL状态获取默认分类ID
  const defaultTypeId = location.state?.typeId || '';
  
  const [formData, setFormData] = useState<ResourceFormData>({
    title: '',
    typeId: defaultTypeId,
    content: '',
    author: '',
    tags: '',
    fileUrl: '',
  });
  
  const [isSubmitting, setIsSubmitting] = useState(false);
  const [isEditing, setIsEditing] = useState(!!id);
  
  // 如果是编辑模式，加载资源数据
  useEffect(() => {
    if (id) {
      const resource = getResourceById(id);
      if (resource) {
        setFormData({
          title: resource.title,
          typeId: resource.typeId,
          content: resource.content,
          author: resource.author,
          tags: resource.tags?.join(', ') || '',
          fileUrl: resource.fileUrl,
        });
      } else {
        toast.error('资源不存在或已被删除');
        navigate('/');
      }
    }
  }, [id, navigate]);
  
  const handleChange = (e: React.ChangeEvent<HTMLInputElement | HTMLTextAreaElement | HTMLSelectElement>) => {
    const { name, value } = e.target;
    setFormData(prev => ({ ...prev, [name]: value }));
  };
  
  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    
    // 表单验证
    if (!formData.title.trim()) {
      toast.error('请输入资源标题');
      return;
    }
    
    if (!formData.typeId) {
      toast.error('请选择资源分类');
      return;
    }
    
    if (!formData.content.trim()) {
      toast.error('请输入资源内容');
      return;
    }
    
    if (!formData.author.trim()) {
      toast.error('请输入作者名称');
      return;
    }
    
    setIsSubmitting(true);
    
    try {
      // 处理标签
      const tags = formData.tags
        .split(',')
        .map(tag => tag.trim())
        .filter(tag => tag);
      
      const resourceData = {
        title: formData.title.trim(),
        typeId: formData.typeId,
        content: formData.content.trim(),
        author: formData.author.trim(),
        tags: tags.length > 0 ? tags : undefined,
        fileUrl: formData.fileUrl?.trim() || undefined,
      };
      
      if (isEditing && id) {
        // 更新资源
        const updatedResource = updateResource(id, resourceData);
        if (updatedResource) {
          toast.success('资源更新成功');
          navigate(`/resource/${id}`);
        } else {
          toast.error('资源更新失败');
        }
      } else {
        // 创建新资源
        const newResource = addResource(resourceData);
        toast.success('资源创建成功');
        navigate(`/resource/${newResource.id}`);
      }
    } catch (error) {
      toast.error('操作失败，请重试');
      console.error(error);
    } finally {
      setIsSubmitting(false);
    }
  };
  
  return (
    <div className="min-h-screen bg-gray-50 dark:bg-gray-900">
      <Navbar />
      
      <main className="max-w-3xl mx-auto py-6 px-4 sm:px-6 lg:px-8">
        <div className="bg-white dark:bg-gray-800 rounded-lg shadow overflow-hidden border border-gray-200 dark:border-gray-700">
          <div className="px-6 py-4 border-b border-gray-200 dark:border-gray-700">
            <h1 className="text-xl font-semibold text-gray-900 dark:text-white">
              {isEditing ? '编辑资源' : '上传新资源'}
            </h1>
          </div>
          
          <form onSubmit={handleSubmit} className="p-6 space-y-6">
            <div>
              <label htmlFor="title" className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-1">
                资源标题 <span className="text-red-500">*</span>
              </label>
              <input
                type="text"
                id="title"
                name="title"
                value={formData.title}
                onChange={handleChange}
                className="w-full px-4 py-2 border border-gray-300 dark:border-gray-600 rounded-md shadow-sm focus:ring-blue-500 focus:border-blue-500 dark:bg-gray-700 dark:text-white"
                required
              />
            </div>
            
            <div>
              <label htmlFor="typeId" className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-1">
                资源分类 <span className="text-red-500">*</span>
              </label>
              <select
                id="typeId"
                name="typeId"
                value={formData.typeId}
                onChange={handleChange}
                className="w-full px-4 py-2 border border-gray-300 dark:border-gray-600 rounded-md shadow-sm focus:ring-blue-500 focus:border-blue-500 dark:bg-gray-700 dark:text-white"
                required
              >
                <option value="">-- 选择分类 --</option>
                {resourceTypes.map(type => (
                  <option key={type.id} value={type.id}>
                    {type.name}
                  </option>
                ))}
              </select>
            </div>
            
            <div>
              <label htmlFor="author" className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-1">
                作者 <span className="text-red-500">*</span>
              </label>
              <input
                type="text"
                id="author"
                name="author"
                value={formData.author}
                onChange={handleChange}
                className="w-full px-4 py-2 border border-gray-300 dark:border-gray-600 rounded-md shadow-sm focus:ring-blue-500 focus:border-blue-500 dark:bg-gray-700 dark:text-white"
                required
              />
            </div>
            
            <div>
              <label htmlFor="tags" className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-1">
                标签 (用逗号分隔)
              </label>
              <input
                type="text"
                id="tags"
                name="tags"
                value={formData.tags}
                onChange={handleChange}
                placeholder="例如: 深度学习, 调度优化, 算法"
                className="w-full px-4 py-2 border border-gray-300 dark:border-gray-600 rounded-md shadow-sm focus:ring-blue-500 focus:border-blue-500 dark:bg-gray-700 dark:text-white"
              />
            </div>
            
            <div>
              <label htmlFor="content" className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-1">
                资源内容 <span className="text-red-500">*</span>
              </label>
              <textarea
                id="content"
                name="content"
                value={formData.content}
                onChange={handleChange}
                rows={8}
                className="w-full px-4 py-2 border border-gray-300 dark:border-gray-600 rounded-md shadow-sm focus:ring-blue-500 focus:border-blue-500 dark:bg-gray-700 dark:text-white"
                required
              ></textarea>
            </div>
            
            <div>
              <label htmlFor="fileUrl" className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-1">
                文件链接 (可选)
              </label>
              <input
                type="text"
                id="fileUrl"
                name="fileUrl"
                value={formData.fileUrl}
                onChange={handleChange}
                placeholder="http://example.com/file.pdf"
                className="w-full px-4 py-2 border border-gray-300 dark:border-gray-600 rounded-md shadow-sm focus:ring-blue-500 focus:border-blue-500 dark:bg-gray-700 dark:text-white"
              />
            </div>
            
            <div className="flex justify-end space-x-3 pt-4 border-t border-gray-200 dark:border-gray-700">
              <button
                type="button"
                onClick={() => navigate(isEditing ? `/resource/${id}` : '/')}
                 className="px-4 py-2 border border-gray-300 dark:border-gray-600 rounded-md shadow-sm text-sm font-medium text-gray-700 dark:text-gray-300 bg-white dark:bg-gray-800 hover:bg-gray-50 dark:hover:bg-gray-700 transition-all duration-300 hover:shadow-sm"
               >
                 <i class="fa-solid fa-arrow-left mr-1"></i> 取消
              </button>
              
              <button
                type="submit"
                disabled={isSubmitting}
                className="px-4 py-2 border border-transparent rounded-md shadow-sm text-sm font-medium text-white bg-blue-600 hover:bg-blue-700 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-blue-500 disabled:opacity-50 disabled:cursor-not-allowed"
              >
                {isSubmitting ? (
                  <>
                    <i class="fa-solid fa-spinner fa-spin mr-2"></i> 处理中...
                  </>
                ) : isEditing ? (
                  '保存修改'
                ) : (
                  '上传资源'
                )}
              </button>
            </div>
          </form>
        </div>
      </main>
    </div>
  );
}